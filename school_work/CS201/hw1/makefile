#Nicholas Grout
#HW1

#Compiler flags
CC = gcc
OUT = -c -o
CFLAGS = -Wall -ansi -pedantic -g

#Objects & Target
OBJS = direction.o hw1.o
TARGET = hw1

all: $(TARGET)

#Objs/Targets instructions
$(TARGET): $(OBJS)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $^ -o $@

direction.o: direction.c hw1.h
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

hw1.o: hw1.c hw1.h
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@


clean:
	@rm -rf $(TARGET)
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
	@rm -f *.out
