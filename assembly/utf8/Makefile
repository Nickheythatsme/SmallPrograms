#Nicholas Grout
.PHONY: clean
CC=g++
CCFLAGS=-g -Wall -std=c++14
C=gcc
CFLAGS= -ansi -pedantic -O3 -Wall -g
AS=nasm
ASFLAGS=-f elf64

all: utf8 utf8_asm 

utf8: main.o utf8.o
	$(CC) $(CCFLAGS) -o $@ $^

utf8_asm: main.o utf8_asm.o
	$(CC) $(CCFLAGS) -o $@ $^

main.o: main.cpp test_case.h test_case.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

utf8.o: utf8.c
	$(CC) $(CCFLAGS) -o $@ -c $^

utf8_asm.o: utf8.asm
	$(AS) $(ASFLAGS) -o $@ $<


clean:
	rm -f *.o utf8 utf8_asm
