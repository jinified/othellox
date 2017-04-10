CC=mpicc

all: othellox
parallel: othellox.c
	$(CC) -Wall -o othellox othellox.c
serial: othello.c
	gcc -g -Wall -o othello othello.c


.PHONY: all clean

clean:
	rm -f *o othellox othello
