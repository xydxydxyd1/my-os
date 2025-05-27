PREFIX = aarch64-none-elf
CC = $(PREFIX)-gcc
FLASH_DEVICE = /dev/sdb1

# Flags
INCLUDES = -iquote. \
		   -iquoteutils
# -mgeneral-regs-only cuz floating point is not enabled
CCFLAGS = -mgeneral-regs-only $(INCLUDES) -g -Wall -O2 -nostartfiles -mstrict-align


# Source files

# Notably does not contain assembly files
SRCS = $(wildcard *.c) \
	   $(wildcard peripherals/*.c) \
	   $(wildcard utils/*.c)
OBJS = startup.o $(SRCS:.c=.o)


# Targets

all: clean kernel8.img

flash: kernel8.img
	mkdir -p mountpoint
	sudo mount $(FLASH_DEVICE) mountpoint
	sudo rm -rf mountpoint/kernel*
	sudo cp kernel8.img mountpoint
	sleep 1
	sudo umount $(FLASH_DEVICE)
	rm -rf mountpoint


# Source compilation

# Name sensitive, used by RPI bootloader
kernel8.img: kernel8.elf
	$(PREFIX)-objcopy -O binary $< $@

kernel8.elf: link.ld $(OBJS)
	$(PREFIX)-ld -nostdlib $(OBJS) -T link.ld -o $@

%.o: %.S
	$(CC) $(CCFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.elf" -type f -delete
	find . -name "*.img" -type f -delete
	find . -name "*.bin" -type f -delete
