#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <linux/if_ether.h>


SEC("xdp")
int xdp_prog_tx(struct xdp_md *ctx) {
	// Modify the destination mac
	void* data = (void*)ctx->data;
	void* data_end = (void*)ctx->data_end;
	struct ethhdr* eth;

	if (data + sizeof(struct ethhdr) < data_end) {
		eth = data; 
		eth->h_source[0] = 1;
		eth->h_source[1] = 1;
		eth->h_source[2] = 1;
		eth->h_source[3] = 1;
		bpf_printk("ciao\n");
	} else {
		bpf_printk("nooooooooooo\n");
	}

	return XDP_TX;
}
char _license[] SEC("license") = "GPL";
