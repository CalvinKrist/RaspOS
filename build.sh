#!/bin/sh
./qemu-system-aarch64 -machine raspi3 -m 128 -kernel $1 -serial null -serial mon:stdio -nographic
