#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <linux/if_ether.h>


SEC("xdp")
int xdp_prog_drop(struct xdp_md *ctx) {
    // Pass all packets
    return XDP_PASS;
}
char _license[] SEC("license") = "GPL";
