#include "utils.h"

using namespace std;

double getElapsedTime(chrono::time_point<chrono::high_resolution_clock> startTime) {
    // Calculates elapsed time using the high resolution clock
    // Returns elapsed time in millisecond (ms)
    auto finish = chrono::high_resolution_clock::now(); 
    chrono::duration<double> elapsed = finish - startTime;
    double elapsedTime = elapsed.count() * 1000;
    return elapsedTime;
}
