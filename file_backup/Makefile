#Nicholas Grout
#HW1

#Compiler flags
CC = gcc
OUT = -c -o
CFLAGS = -Wall -g

#Objects & Target
OBJS = track_file.o main.o
TARGET = file_backup

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $^ -o $@

#Objs/Targets instructions
%.o: %.c
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

clean:
	@rm -rf $(TARGET)
	@rm -rf $(OBJS)
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
	@rm -f *.out
