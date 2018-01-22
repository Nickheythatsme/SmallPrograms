#Compiler flags
CC = g++
CFLAGS = -Wall -g
OUT = -c -o

#Paths
BIN_P = ../bin

#Objs/Targets
OBJS = celestial_body.o planet.o moon.o outer_planet.o inner_planet.o


all: $(addprefix $(BIN_P)/, $(OBJS) )


#BUILD OBJECTS
$(BIN_P)/%.o: %.cpp %.h
	@mkdir -p $(BIN_P)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@


clean:
	@rm -rf $(BIN_P)
	@rm -f *.swp
	@rm -f *.vim
	@rm -f *.o
