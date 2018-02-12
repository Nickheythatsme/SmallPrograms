#Compiler flags
CC = g++
CFLAGS = -Wall -g -std=c++11
OUT = -c -o

#PATHS
BIN = bin

#Objs/Targets
OBJS = row.o matrix.o

LOG = compile_log.txt

all: $(OBJS)


#MAKING OBJECTS
row.o: test_row.cpp row.h row.cpp
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

matrix.o: test_matrix.cpp matrix.h matrix.cpp
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
	@rm -f *.out
	@rm -f *.gch
