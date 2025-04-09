#!/bin/bash
# run.sh 
#

qemu_cmd="qemu-system-aarch64 \
    -s -S \
    -M versatilepb \
    -cpu cortex-a72 \
    -monitor stdio \
    -kernel ./test.elf \
    $*"

make

tmux split-window -h
tmux last-pane
tmux send-keys -t - "$qemu_cmd" Enter
sleep 3
aarch64-none-elf-gdb -ex "target remote :1234" test.elf
