PREFIX = aarch64-none-elf
CC = $(PREFIX)-gcc $(INCLUDES)

SRCS = $(wildcard *.c) $(wildcard peripherals/*.c)
OBJS = startup.o $(SRCS:.c=.o)

CCFLAGS = -mcpu=cortex-a72 -g

main.bin: main.elf
	$(PREFIX)-objcopy -O binary $^ $@

main.elf: link.ld $(OBJS)
	$(PREFIX)-ld -T link.ld $(OBJS) -o $@

%.o: %.S
	$(PREFIX)-as $(CCFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(CCFLAGS) $^ -o $@

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.elf" -type f -delete
	find . -name "*.bin" -type f -delete
