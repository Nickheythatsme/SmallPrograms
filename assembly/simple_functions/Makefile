#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -g

all: functions functions_asm 

functions: main.o functions.o
	gcc -g -o $@ $(CFLAGS) $^

functions_asm: main.o functions_asm.o
	gcc -g -o $@ $(CFLAGS) $^

main.o: main.c
	gcc -g -o $@ $(CFLAGS) -c $^

functions.o: functions.c
	gcc -g -o $@ $(CFLAGS) -c $^

functions_asm.o: functions.S
	as -o $@ $^


clean:
	rm -f *.o functions functions_asm
