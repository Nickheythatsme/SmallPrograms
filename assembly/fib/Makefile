#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g

all: fib fib_asm

fib: main.o fib.o
	gcc -g -o $@ $(CFLAGS) $^

fib_asm: main.o fib_asm.o
	gcc -g -o $@ $(CFLAGS) $^

main.o: main.c
	gcc -g -o $@ $(CFLAGS) -c $^

fib.o: fib.c
	gcc -g -o $@ $(CFLAGS) -c $^

fib_asm.o: fib_asm.S
	as -o $@ $^


clean:
	rm -f *.o fib fib_asm
