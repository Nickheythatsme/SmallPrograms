#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g
ASFLAGS= --64

all: lower lower_asm_simple lower_asm_complex

lower: main.o lower.o
	gcc -g -o $@ $(CFLAGS) $^

lower_asm_simple: main.o lower_asm_simple.o
	gcc -g -o $@ $(CFLAGS) $^

lower_asm_complex: main.o lower_asm_complex.o
	gcc -g -o $@ $(CFLAGS) $^

main.o: main.c
	gcc -g -o $@ $(CFLAGS) -c $^

lower.o: lower.c
	gcc -g -o $@ $(CFLAGS) -c $^

lower_asm_complex.o: lower_asm_complex.S
	as --64 -o $@ $<

lower_asm_simple.o: lower_asm_simple.S
	as --64 -o $@ $<



clean:
	rm -f *.o lower lower_asm_simple lower_asm_complex
