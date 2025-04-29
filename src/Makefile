PREFIX = aarch64-none-elf
CC = $(PREFIX)-gcc $(INCLUDES)

SRCS = $(wildcard *.c) $(wildcard peripherals/*.c) $(wildcard hardware/*.c)
OBJS = startup.o $(SRCS:.c=.o)

FLAGS = -mcpu=cortex-a72 -g

main.bin: main.elf
	$(PREFIX)-objcopy -O binary $^ $@

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
