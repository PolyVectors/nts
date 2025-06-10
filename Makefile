.PHONY: build std clean

build: std
	gcc -Wall -Wextra -m64 -std=c99 -nostdlib -ffreestanding -fno-stack-protector -s -O3 src/main.c termios/termios.c bin/* -o main

std: src/main.c std/sys.asm std/io.asm
	fasm std/io.asm bin/io.o
	fasm std/mem.asm bin/mem.o
	fasm std/sys.asm bin/sys.o

	fasm termios/ioctl.asm bin/ioctl.o

clean:
	rm -f bin/sys.o bin/io.o main
