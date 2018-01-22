#Compiler flags
CC = g++
CFLAGS = -Wall -g -Wwrite-strings
OUT = -c -o

#Paths
BIN_P = bin
DIRS = solar_system_files

#Objs/Targets
OBJS = main.o galaxy.o
TARGET = space_ship

all: subsystem $(TARGET)

$(TARGET): $(addprefix $(BIN_P)/,$(OBJS) )
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@echo "Linking:"
	@$(CC) $(CFLAGS) $(BIN_P)/* -o $@


#BUILD FILES IN DIRECTORIES
subsystem: $(DIRS)
	@$(MAKE) -C $^

$(BIN_P)/%.o: %.cpp %.h
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

$(BIN_P)/main.o: main.cpp
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@


clean:
	@rm -rf $(BIN_P)
	@rm -f $(TARGET)
	@rm -f *.swp
	@rm -f *.vim
	@rm -f *.o
