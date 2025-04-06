# Aliases for ARM linux
gccpath="$(pwd)/utils/gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu"
export GNUPATH="$(pwd)/utils/gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu"
alias gcc="$gccpath-gcc"
alias as="$gccpath-as"
alias objdump="$gccpath-objdump"
alias ld="$gccpath-ld"
alias qemu="qemu-aarch64 -L $GNUPATH/aarch64-none-linux-gnu/libc/"
