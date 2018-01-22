#Compiler flags
CC = g++
CFLAGS = -Wall -g -std=c++11
OUT = -c -o

#Paths
BIN_P = bin
DIRS = contact 

#Objs/Targets
OBJS = main.o event.o text.o enode.o tree.o
TARGET = cs_discord

all: subsystem $(TARGET) 


#BUILD TARGET EXECUTABLE & LINK
$(TARGET): $(addprefix $(BIN_P)/, $(OBJS) )
	@echo "linking files"
	@echo "compiling: " $(TARGET)
	@$(CC) $(CFLAGS) $(BIN_P)/* -o $(TARGET)


#BUILD OBJECTS
$(BIN_P)/%.o: %.cpp %.h
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

$(BIN_P)/main.o: main.cpp
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

$(BIN_P)/text.o: text.cpp
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@


#BUILD FILES IN DIRECTORIES
subsystem: $(DIRS)
	@$(MAKE) -C $^/

clean:
	@rm -rf $(BIN_P)
	@rm -f $(TARGET)
	@rm -f *.swp
	@rm -f *.vim
	@rm -f *.o
