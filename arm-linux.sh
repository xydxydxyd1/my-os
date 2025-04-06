# Aliases for ARM linux
export PREFIX="$(pwd)/utils/gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu"
export GNUPATH="$(pwd)/utils/gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu"
alias gcc="$PREFIX-gcc"
alias as="$PREFIX-as"
alias objdump="$PREFIX-objdump"
alias ld="$PREFIX-ld"
alias qemu="qemu-aarch64 -L $GNUPATH/aarch64-none-linux-gnu/libc/"
