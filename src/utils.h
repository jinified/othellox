#ifndef __UTILS_H__
#define __UTILS_H__

#include <chrono>

double getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> startTime);

#endif
