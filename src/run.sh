#!/bin/bash

make
qemu-system-aarch64 \
    -M raspi4b \
    -kernel ./main.elf \
    -nographic \
    $*
