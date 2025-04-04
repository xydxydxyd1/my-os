PREFIX = ../utils/gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu

main.out: main.o
	$(PREFIX)-ld -o main.out main.o

main.o: main.S
	$(PREFIX)-as -o main.o main.S

clean:
	rm -rf main.o main.out
