PREFIX = aarch64-none-elf
CC = $(PREFIX)-gcc $(INCLUDES)

SRCS = $(wildcard *.c) $(wildcard peripherals/*.c) $(wildcard hardware/*.c) $(wildcard utils/*.c)
OBJS = startup.o $(SRCS:.c=.o)

FLAGS = -mcpu=cortex-a72 -g

flash: kernel8.img
	mkdir -p mountpoint
	sudo mount /dev/sda1 mountpoint
	sudo rm -rf mountpoint/kernel*
	sudo cp kernel8.img mountpoint
	sudo umount /dev/sda1
	rm -rf mountpoint

# Name sensitive, used by RPI bootloader
kernel8.img: kernel8.elf
	$(PREFIX)-objcopy -O binary $^ $@

kernel8.elf: link.ld $(OBJS)
	$(PREFIX)-ld -T link.ld $(OBJS) -o $@

%.o: %.S
	$(PREFIX)-as $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) -c -iquote . $(FLAGS) $^ -o $@

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.elf" -type f -delete
	find . -name "*.bin" -type f -delete
