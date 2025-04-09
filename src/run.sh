#!/bin/bash
# run.sh 
#
while getopts "" opt; do
    case $opt in
	\?)
	    echo "Invalid option: -$OPTARG" >&2
	    ;;
    esac
done
if [[ "$#" -ne 0 ]]; then
    echo "Illegal number of parameters" >&2
    exit 1
fi

qemu-system-aarch64 \
    -M versatilepb \
    -cpu cortex-a72 \
    -monitor stdio \
    -device loader,file=./test.bin
