#Nicholas Grout
#HW1

#Compiler flags
CC = gcc
OUT = -c -o
CFLAGS = -Wall -ansi -pedantic -g

#Objects & Target
OBJS = set_bits.o show_bits.o 

all: $(OBJS)

#Objs/Targets instructions
set_bits.o: set_bits.c
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

show_bits.o: show_bits.c
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@


clean:
	@rm -rf $(TARGET)
	@rm -rf $(OBJS)
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
	@rm -f *.out
