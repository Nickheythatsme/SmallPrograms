#Nicholas Grout
.PHONY: clean
CFLAGS= -std=c++14 -Wall -g
OBJS= main.o grid.o clue.o crossword.o
TARGET= crossword

all: $(TARGET)

$(TARGET): $(OBJS)
	g++ $(CFLAGS) $^ -o $@

main.o: main.cpp
	g++ $(CFLAGS) $^ -c -o $@

%.o: %.cpp %.h
	g++ $(CFLAGS) $< -c -o $@

clean:
	rm -f *.o $(TARGET)
