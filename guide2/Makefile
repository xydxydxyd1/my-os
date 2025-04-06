CCFLAGS = -mcpu=arm926ej-s -g

test.bin: test.elf
	arm-none-eabi-objcopy -O binary $^ $@

test.elf: test.ld test.o startup.o
	arm-none-eabi-ld -T test.ld test.o startup.o -o $@

%.o: %.S
	arm-none-eabi-as -mcpu=arm926ej-s -g $^ -o $@

%.o: %.c
	arm-none-eabi-gcc -c -mcpu=arm926ej-s -g $^ -o $@

clean:
	rm -rf *.o *.elf *.bin
