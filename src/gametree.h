#ifndef __GAMETREE_H__
#define __GAMETREE_H__

#include <iostream>
#include "common.h"
#include "board.h"
#include "node.h"
using namespace std;

class GameTree { 

private:
	Node *root;

protected:
	Side maximizer;
    int maxDepth;
    int maxNodes;

public:
    GameTree(Board *board, Side side, int maxDepth, int maxNodes);
	~GameTree();

	Move *findBestMove(int depth, bool isMoveOrdered);
	void search(Node *startingNode, int depth);

};

#endif
