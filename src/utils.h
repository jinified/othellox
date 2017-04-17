#ifndef __UTILS_H__
#define __UTILS_H__

#include <chrono>
#include "board.h"

double getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> startTime);
unsigned long long int randomInt();
unsigned long long int *initZobristTable(int row, int col, int piece);
unsigned long long int computeHash(Board *board, unsigned long long int *zTable);

#endif
