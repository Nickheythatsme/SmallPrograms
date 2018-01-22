#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g

all: encrypt encrypt_asm

encrypt: main.o encrypt.o
	gcc -g -o $@ $(CFLAGS) $^

encrypt_asm: main.o encrypt_asm.o
	gcc -g -o $@ $(CFLAGS) $^

main.o: main.c
	gcc -g -o $@ $(CFLAGS) -c $^

encrypt.o: encrypt.c
	gcc -g -o $@ $(CFLAGS) -c $^

encrypt_asm.o: encrypt_asm.S
	as -o $@ $^


clean:
	rm -f *.o encrypt encrypt_asm
