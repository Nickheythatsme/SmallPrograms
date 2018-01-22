#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g
ASFLAGS= --64

all: hash hash_asm

hash: main.o hash.o
	gcc -g -o $@ $(CFLAGS) $^

hash_asm: main.o hash_asm.o
	gcc -g -o $@ $(CFLAGS) $^

main.o: main.c
	gcc -g -o $@ $(CFLAGS) -c $^

hash.o: hash.c
	gcc -g -o $@ $(CFLAGS) -c $^

hash_asm.o: hash_asm.S
	as --64 -o hash_asm.o $<


clean:
	rm -f *.o hash hash_asm
