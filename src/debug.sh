#!/bin/bash
# run.sh 
#

qemu_cmd="qemu-system-arm \
    -s -S \
    -M orangepi-pc \
    -monitor stdio \
    -kernel ./main.elf \
    $*"

make

tmux split-window -h
tmux last-pane
tmux send-keys -t - "$qemu_cmd" Enter
sleep 3
aarch64-none-elf-gdb -ex "target remote :1234" main.elf
