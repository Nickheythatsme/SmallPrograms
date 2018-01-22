#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g
ASFLAGS= --64

all: interrupts interrupts_asm

interrupts: main.o interrupts.o
	gcc -g -o $@ $(CFLAGS) $^

interrupts_asm: main.o interrupts_asm.o
	gcc -g -o $@ $(CFLAGS) $^

main.o: main.c
	gcc -g -o $@ $(CFLAGS) -c $^

interrupts.o: interrupts.c
	gcc -g -o $@ $(CFLAGS) -c $^

interrupts_asm.o: interrupts_asm.S
	as --64 -o interrupts_asm.o $<


clean:
	rm -f *.o interrupts interrupts_asm
