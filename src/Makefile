CC=mpicxx
CFLAGS=-std=c++11 -Wall -g

TARGETS = othellox othellos
OBJS = board.o gametree.o node.o utils.o

all: $(TARGETS)

utils.o: utils.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

node.o: node.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

gametree.o: gametree.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

board.o: board.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

othellox: othellox.cpp $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+

othellos: othellos.cpp $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+

.PHONY: all clean

clean:
	rm -f *o $(TARGETS)
