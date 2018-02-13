#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g

all: stack stack_asm

stack: main.o stack.o
	gcc -g -o $@ $(CFLAGS) $^

stack_asm: main.o stack_asm.o
	gcc -g -o $@ $(CFLAGS) $^

main.o: main.c
	gcc -g -o $@ $(CFLAGS) -c $^

stack.o: stack.c
	gcc -g -o $@ $(CFLAGS) -c $^

stack_asm.o: stack_asm.S
	as -o $@ $^


clean:
	rm -f *.o stack stack_asm
