.PHONY: build std clean

build: std
	gcc -nostdlib -ffreestanding -s -O3 src/main.c bin/* -o main

std: src/main.c std/sys.asm std/io.asm
	fasm std/sys.asm bin/sys.o
	fasm std/io.asm bin/io.o

clean:
	rm -f bin/sys.o bin/io.o main
