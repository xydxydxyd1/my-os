# Hardware specification (modify for different hardware)
# CPU is specified in flags, not here.

PREFIX = aarch64-none-elf
CC = $(PREFIX)-gcc
HARDWARE = hardware/rpi4b


# Flags

INCLUDES = -iquote. \
		   -iquoteutils \
		   -iquote$(HARDWARE)
LDFLAGS = -mcpu=cortex-a72 -g
CCFLAGS = $(LDFLAGS) $(INCLUDES)


# Source files

SRCS = $(wildcard *.c) \
	   $(wildcard peripherals/*.c) \
	   $(wildcard hardware/*.c) \
	   $(wildcard utils/*.c) \
	   $(wildcard $(HARDWARE)/*.c)
OBJS = startup.o $(SRCS:.c=.o)


# Targets

image: kernel8.img

flash: image
	mkdir -p mountpoint
	sudo mount /dev/sda1 mountpoint
	sudo rm -rf mountpoint/kernel*
	sudo cp kernel8.img mountpoint
	sudo umount /dev/sda1
	rm -rf mountpoint


# Source compilation

# Name sensitive, used by RPI bootloader
kernel8.img: kernel8.elf
	$(PREFIX)-objcopy -O binary $^ $@

kernel8.elf: link.ld $(OBJS)
	$(PREFIX)-ld -T link.ld $(OBJS) -o $@

%.o: %.S
	$(PREFIX)-as $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(CCFLAGS) $^ -o $@

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.elf" -type f -delete
	find . -name "*.img" -type f -delete
	find . -name "*.bin" -type f -delete
