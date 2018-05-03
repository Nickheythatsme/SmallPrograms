#Nicholas Grout
#HW1

#Compiler flags
CC = gcc
OUT = -c -o
CFLAGS = -Wall -g

#Objects & Target
OBJS = server.o client.o 

all: $(OBJS)

#Objs/Targets instructions
server.o: server.c
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

client.o: client.c
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@


clean:
	@rm -rf $(TARGET)
	@rm -rf $(OBJS)
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
	@rm -f *.out
