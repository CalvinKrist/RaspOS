#!/bin/sh
./../qemu-2.12.1/aarch64-softmmu/qemu-system-aarch64 -machine raspi3 -m 128 -kernel $1 -serial null -serial mon:stdio -nographic
