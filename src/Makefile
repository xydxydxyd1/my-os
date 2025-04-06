PREFIX = aarch64-none-elf
CC = $(PREFIX)-gcc

CCFLAGS = -mcpu=cortex-a72 -g

test.bin: test.elf
	$(PREFIX)-objcopy -O binary $^ $@

test.elf: test.ld test.o startup.o
	$(PREFIX)-ld -T test.ld test.o startup.o -o $@

%.o: %.S
	$(PREFIX)-as $(CCFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(CCFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf *.bin
