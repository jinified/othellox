#include <chrono>
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

#include "gametree.h"
#include "utils.h"
#include "common.h"

GameTree::GameTree(Board *board, Side maximizer,
                   int maxDepth, int maxNodes, int timeout) {
    // this is our side
    this->maximizer = maximizer;
    this->maxDepth = maxDepth;
    this->designatedDepth = maxDepth;
    this->maxNodes = maxNodes;
    this->timeout = timeout * 1000; // Convert to milliseconds
    this-> nodes = 0;
    root = new Node(NULL, maximizer == BLACK ? WHITE : BLACK, maximizer, board);

    // Transposition table
    zTable = initZobristTable(board->row, board->col, 2);
}

GameTree::~GameTree() {
    // free some stuff
    delete zTable;
}

Move *GameTree::findBestMove(int depth, bool isMoveOrdered) {
    Board *board = root->getBoard();
    // Assigned searched depth
    designatedDepth = depth;
    startTime = chrono::high_resolution_clock::now(); 

    vector<Move> moves = board->getMoves(maximizer);
    // Sort Moves according to evaluation score. Can be slow
    if (isMoveOrdered) {
        std::sort(moves.begin(), moves.end(), [&] (Move m1, Move m2)
            {
                Board *b1 = board->copy();
                b1->doMove(&m1, maximizer);
                Board *b2 = board->copy();
                b2->doMove(&m2, maximizer);
                int b1_score = b1->getScore(maximizer);
                int b2_score = b2->getScore(maximizer);
                return b1_score > b2_score;
            }
        );
    }

    Node *best = NULL;

    for (int i = 0; i < moves.size(); i++) {
        Move *move = new Move(moves[i].getX(), moves[i].getY());
        Board *newBoard = board->copy();
        newBoard->doMove(move, maximizer);
        Node *child = new Node(move, maximizer, maximizer, newBoard);

        // pass alpha and beta values down
        child->setAlpha(root->getAlpha());
        child->setBeta(root->getBeta());

        // search child
        search(child, depth - 1);

        if (best == NULL || child->getBeta() > best->getBeta()) {
            best = child;
        }
    }

    double elapsedTime = getElapsedTime(startTime);

    Move *chosenMove = best->getMove();

    printf("Best moves: { %s }\n"
           "Number of boards assessed: %d\n"
           "Depth of boards: %d\n"
           "Entire space: %s\n"
           "Elapsed time in seconds: %f\n", chosenMove->getPos().c_str(),
            nodes, depth, nodes == board->isDone() ? "true" : "false",
            elapsedTime / 1000);
    // printf("\nP:%s,D:%d,N:%d,T:%f,FULL: %s\n",
    //     maximizer == WHITE ? "White" : "Black", depth, nodes,
    //     elapsedTime, nodes == board->isDone() ? "true" : "false");

    return best->getMove();
}

void GameTree::search(Node *startingNode, int depth) {
    // Minimax search with alpha-beta pruning
    this->nodes ++; // Increment node counter

    if (getElapsedTime(startTime) > timeout) {
        return;
    }

    if (depth == 0) {
        int score = startingNode->getBoard()->getScore(maximizer);
        startingNode->setAlpha(score);
        startingNode->setBeta(score);
        return;
    }
    Board *board = startingNode->getBoard();

    // Hash of current board configuration and check using transposition table
    unsigned long long int boardHash = computeHash(board, zTable);

    if (tt.find(boardHash)  != tt.end()) {
        TableEntry *e = tt[boardHash];
        if (e->depth > designatedDepth) {
            startingNode->setAlpha(e->alpha);
            startingNode->setBeta(e->beta);
        }
    }

    Side oppositeSide = startingNode->getSide() == BLACK ? WHITE : BLACK;
    vector<Move> moves = board->getMoves(oppositeSide);
    for (int i = 0; i < moves.size(); i++) {
        // create the next child
        Move *move = new Move(moves[i].getX(), moves[i].getY());
        Board *newBoard = board->copy();
        newBoard->doMove(move, oppositeSide);
        Node *child = new Node(move, oppositeSide, maximizer, newBoard);

        // pass alpha and beta values down
        child->setAlpha(startingNode->getAlpha());
        child->setBeta(startingNode->getBeta());

        // search child
        search(child, depth - 1);

        // MINIMAX PART
        if (startingNode->getSide() == maximizer) {
            int score = min(startingNode->getBeta(), child->getAlpha());
            startingNode->setValue(score);
            startingNode->setBeta(score);
        } else {
            int score = max(startingNode->getAlpha(), child->getBeta());
            startingNode->setValue(score);
            startingNode->setAlpha(score);
        }

        delete child;

        if (startingNode->getAlpha() > startingNode->getBeta()) {
            return;
        }
    }

    // Stores the best result in transposition table
    tt[boardHash] = new TableEntry(startingNode->getMove(),
        startingNode->getAlpha(), startingNode->getBeta(), depth);
}
