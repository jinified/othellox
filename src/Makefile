CC=mpicxx
CFLAGS=-std=c++11 -Wall -g

TARGETS = othellox othellos
OBJS = board.o

all: $(TARGETS)

board.o: board.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

othellox: othellox.cpp $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+

othellos: othellos.cpp $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+

.PHONY: all clean

clean:
	rm -f *o $(TARGETS)
