#Compiler flags
CC = g++
CFLAGS = -Wall -g
OUT = -c -o

#Paths
BIN_P = ../bin

#Objs/Targets
OBJS = contact.o contact_node.o contact_group.o 

all: $(addprefix $(BIN_P)/, $(OBJS) )

#BUILD OBJECTS
$(BIN_P)/%.o: %.cpp %.h
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

$(BIN_P)/contact_node.o: contact_node.cpp contact_group.h
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

clean:
	@rm -rf $(BIN_P)
	@rm -f $(TARGET)
	@rm -f *.swp
	@rm -f *.vim
	@rm -f *.o
