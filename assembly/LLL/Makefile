#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g

all: LLL LLL_asm 

LLL: main.o LLL.o
	gcc -g -o $@ $(CFLAGS) $^

LLL_asm: main.o LLL_asm.o
	gcc -g -o $@ $(CFLAGS) $^

main.o: main.c
	gcc -g -o $@ $(CFLAGS) -c $^

LLL.o: LLL.c
	gcc -g -o $@ $(CFLAGS) -c $^

LLL_asm.o: LLL.S
	as -o $@ $^


clean:
	rm -f *.o LLL LLL_asm
