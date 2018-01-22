CC = g++
CFLAGS = -Wall -g
OUT = -c -o

OBJS = graph.o vertex_edge.o main.o
TARGET = graph


#BUILD TARGET EXECUTABLE
$(TARGET): $(OBJS)
	@echo "linking: " $^
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp %.h
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

main.o: main.cpp
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

clean:
	rm -f $(TARGET)
	rm -f *.o
