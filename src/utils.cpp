#include <bits/stdc++.h>
#include <vector>

#include "utils.h"
#include "board.h"

using namespace std;

mt19937 mt(01234567);

double getElapsedTime(chrono::time_point<chrono::high_resolution_clock> startTime) {
    // Calculates elapsed time using the high resolution clock
    // Returns elapsed time in millisecond (ms)
    auto finish = chrono::high_resolution_clock::now(); 
    chrono::duration<double> elapsed = finish - startTime;
    double elapsedTime = elapsed.count() * 1000;
    return elapsedTime;
}

// Zobrist Hashing

unsigned long long int randomInt() {
    // Generates random number from given distribution
    uniform_int_distribution<unsigned long long int> dist(0, UINT64_MAX);
    return dist(mt);
}

unsigned long long int* initZobristTable(int row, int col, int piece) {
    // Generates Zobrist table for hashing 
    unsigned long long int *ZobristTable = new unsigned long long int[row * col * piece];

    for (int i=0; i < row; i++) {
        for (int j=0; j < col; j++) {
            for (int k=0; k < 2; k++) {
                ZobristTable[(i * col + j) * piece + k] = randomInt();
            }
        }
    }
    return ZobristTable;
}

unsigned long long int computeHash(Board *board, unsigned long long int* zTable) {
    unsigned long long int h = 0;
    int row = board->row;
    int col = board->col;
    for (int x=0; x < col; x++) {
        for (int y=0; y < row; y++) {
            if (board->taken[x + row * y] == 1) {
                int piece = board->black[x + row * y];
                h ^= zTable[(x * row + y) * 2 + piece];
            }
        }
    }
    return h;
}
