#!/bin/bash

make clean;
make serial;

echo "Test 1"

./othello test/initialbrd2.txt test/evalparams.txt &&

echo "Test 2"

./othello test/initialbrd3.txt test/evalparams.txt
