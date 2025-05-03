#!/bin/bash

make
qemu-system-arm \
    -M orangepi-pc \
    -sd ./main.img \
    $*
