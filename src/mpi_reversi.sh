#!/bin/bash
make clean
make
mpirun --oversubscribe -np $1 ./othellox $2 $3
