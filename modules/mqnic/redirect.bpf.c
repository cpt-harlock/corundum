#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <linux/in.h>
#include <linux/if_arp.h>
#include <linux/byteorder/little_endian.h>


SEC("xdp")
int xdp_prog_redirect(struct xdp_md *ctx) {
	return bpf_redirect(4, 0);
}
char _license[] SEC("license") = "GPL";
