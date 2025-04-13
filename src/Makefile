PREFIX = aarch64-none-elf
CC = $(PREFIX)-gcc

CCFLAGS = -mcpu=cortex-a72 -g

main.bin: main.elf
	$(PREFIX)-objcopy -O binary $^ $@

main.elf: link.ld main.o startup.o
	$(PREFIX)-ld -T link.ld main.o startup.o -o $@

%.o: %.S
	$(PREFIX)-as $(CCFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(CCFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf *.bin
