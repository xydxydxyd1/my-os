#!/bin/bash

make
qemu-system-arm \
    -M orangepi-pc \
    -kernel ./main.elf \
    $*
