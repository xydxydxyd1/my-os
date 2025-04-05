# Taken from https://www.rpi4os.com/part2-building/

CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
GCCPATH = ../utils/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-elf/bin
PREFIX = ../utils/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-elf/bin/aarch64-none-elf

all: clean kernel8.img

boot.o: boot.S
	$(PREFIX)-gcc $(GCCFLAGS) -c boot.S -o boot.o

%.o: %.c
	$(PREFIX)-gcc $(GCCFLAGS) -c $< -o $@

kernel8.img: boot.o $(OFILES)
	$(PREFIX)-ld -nostdlib boot.o $(OFILES) -T link.ld -o kernel8.elf
	$(PREFIX)-objcopy -O binary kernel8.elf kernel8.img

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true
