#ifndef __GAMETREE_H__
#define __GAMETREE_H__

#include <iostream>
#include <unordered_map>
#include "common.h"
#include "board.h"
#include "node.h"
#include "utils.h"
using namespace std;

class GameTree { 

private:
	Node *root;
    unsigned long long int *zTable;

protected:
	Side maximizer;
    int maxDepth;
    int maxNodes;
    int designatedDepth;
    chrono::time_point<chrono::high_resolution_clock> startTime;

public:
    GameTree(Board *board, Side side, int maxDepth, int maxNodes, int timeout);
	~GameTree();

    int timeout; // timeout in seconds
    int nodes;  // number of nodes expanded
	Move *findBestMove(int depth, bool isMoveOrdered);
	void search(Node *startingNode, int depth);
    // Transposition table
    unordered_map<unsigned long long int, TableEntry*> tt;

    

};

#endif
