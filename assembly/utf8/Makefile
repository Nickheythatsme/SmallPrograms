#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g
CC=gcc
AS=nasm

all: utf8 utf8_asm 

utf8: main.o utf8.o
	$(CC) -g -o $@ $(CFLAGS) $^

utf8_asm: main.o utf8_asm.o
	$(CC) -g -o $@ $(CFLAGS) $^

main.o: main.c
	$(CC) -g -o $@ $(CFLAGS) -c $^

utf8.o: utf8.c
	$(CC) -g -o $@ $(CFLAGS) -c $^

utf8_asm.o: utf8.asm
	$(AS) -f elf64 -o $@ $<


clean:
	rm -f *.o utf8 utf8_asm
