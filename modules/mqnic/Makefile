# SPDX-License-Identifier: BSD-2-Clause-Views
# Copyright (c) 2019-2023 The Regents of the University of California

ifneq ($(KERNELRELEASE),)

# object files to build
obj-m += mqnic.o
mqnic-y += mqnic_main.o
mqnic-y += mqnic_devlink.o
mqnic-y += mqnic_res.o
mqnic-y += mqnic_reg_block.o
mqnic-y += mqnic_irq.o
mqnic-y += mqnic_dev.o
mqnic-y += mqnic_if.o
mqnic-y += mqnic_port.o
mqnic-y += mqnic_netdev.o
mqnic-y += mqnic_sched_block.o
mqnic-y += mqnic_scheduler.o
mqnic-y += mqnic_ptp.o
mqnic-y += mqnic_i2c.o
mqnic-y += mqnic_board.o
mqnic-y += mqnic_clk_info.o
mqnic-y += mqnic_stats.o
mqnic-y += mqnic_tx.o
mqnic-y += mqnic_rx.o
mqnic-y += mqnic_cq.o
mqnic-y += mqnic_eq.o
mqnic-y += mqnic_ethtool.o

ifneq ($(DEBUG),)
ccflags-y += -DDEBUG
endif

else

ifneq ($(KERNEL_SRC),)
# alternatively to variable KDIR accept variable KERNEL_SRC as used in
# PetaLinux/Yocto for example
KDIR ?= $(KERNEL_SRC)
endif

KDIR ?= /lib/modules/$(shell uname -r)/build

all: modules

help modules modules_install clean:
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

install: modules_install

XDP_SOURCES = $(wildcard *.bpf.c)
XDP_OBJECTS = $(XDP_SOURCES:.bpf.c=.bpf.o)

%.bpf.o: %.bpf.c
	clang -O2 -g -target bpf -c $< -o $@

xdp: $(XDP_OBJECTS)
	@echo "XDP objects built: $(XDP_OBJECTS)"

xdp_clean:
	rm -f $(XDP_OBJECTS)



endif
