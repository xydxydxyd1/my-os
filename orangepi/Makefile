PREFIX = arm-none-eabi
CC = $(PREFIX)-gcc $(INCLUDES)

SRCS = $(wildcard *.c) $(wildcard peripherals/*.c) $(wildcard hardware/*.c) $(wildcard utils/*.c)
OBJS = startup.o $(SRCS:.c=.o)

FLAGS = -mcpu=cortex-a7 -g

main.img: main.elf
	$(PREFIX)-objcopy -O binary $^ $@
	qemu-img resize -f raw $@ 16K

main.elf: link.ld $(OBJS)
	$(PREFIX)-ld -T link.ld $(OBJS) -o $@

%.o: %.S
	$(PREFIX)-as $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) -c -iquote . $(FLAGS) $^ -o $@

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.elf" -type f -delete
	find . -name "*.bin" -type f -delete
	find . -name "*.img" -type f -delete
