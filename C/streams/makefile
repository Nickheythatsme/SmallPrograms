#Nicholas Grout
#HW1

#Compiler flags
CC = gcc
OUT = -c -o
CFLAGS = -Wall -ansi -pedantic -g

#Objects & Target
OBJS = random.o read_rand.o

all: $(OBJS)

#Objs/Targets instructions
read_rand.o: read_rand.c
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

random.o: random.c
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@


clean:
	@rm -rf $(TARGET)
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
	@rm -f *.out
