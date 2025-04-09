#!/bin/bash
# run.sh 
#

qemu-system-aarch64 \
    -M versatilepb \
    -cpu cortex-a72 \
    -monitor stdio \
    -device loader,file=./test.bin \
    $*
