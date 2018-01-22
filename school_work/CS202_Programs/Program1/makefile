#Compiler flags
CC = g++
CFLAGS = -Wall -g -Wwrite-strings
OUT = -c -o

#Paths
BIN_P = bin
DIRS = celestial_bodies 

#Objs/Targets
OBJS = node.o solar_system.o galaxy.o main.o 
TARGET = galaxy

all: $(TARGET) 


#BUILD TARGET EXECUTABLE & LINK
$(TARGET): subsystem $(addprefix $(BIN_P)/, $(OBJS) )
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


#BUILD FILES IN DIRECTORIES
subsystem: $(DIRS)
	@$(MAKE) -C $^

clean:
	@rm -rf $(BIN_P)
	@rm -f $(TARGET)
	@rm -f *.swp
	@rm -f *.vim
	@rm -f *.o
