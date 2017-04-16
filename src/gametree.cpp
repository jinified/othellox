#include <chrono>
#include <algorithm>

#include "gametree.h"
#include "utils.h"
#include "common.h"

GameTree::GameTree(Board *board, Side maximizer, int maxDepth, int maxNodes) {
    // this is our side
    this->maximizer = maximizer;
    this->maxDepth = maxDepth;
    this->maxNodes = maxNodes;
    root = new Node(NULL, maximizer == BLACK ? WHITE : BLACK, maximizer, board);
}

GameTree::~GameTree() {
    // free some stuff
}

Move *GameTree::findBestMove(int depth, bool isMoveOrdered) {
    auto startTime = chrono::high_resolution_clock::now(); 
    Board *board = root->getBoard();
    vector<Move> moves = board->getMoves(maximizer);
    //
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
    printf("\nP:%s,D:%d,T:%f\n", maximizer == WHITE ? "White" : "Black", depth, elapsedTime);
    for (Move m: moves) {
        Board *b1 = board->copy();
        b1->doMove(&m, maximizer);
        int score = b1->getScore(maximizer);
        printf("\n[%d,%d] = %d", m.getX(), m.getY(), score);
    }

    return best->getMove();
}

void GameTree::search(Node *startingNode, int depth) {
    // Minimax search with alpha-beta pruning

    if (depth == 0) {
        startingNode->setAlpha(startingNode->getBoard()->getScore(maximizer));
        startingNode->setBeta(startingNode->getBoard()->getScore(maximizer));
        return;
    }
    Board *board = startingNode->getBoard();
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

        if (startingNode->getSide() == maximizer) {
            startingNode->setBeta(min(startingNode->getBeta(), child->getAlpha()));
        } else {
            startingNode->setAlpha(max(startingNode->getAlpha(), child->getBeta()));
        }

        delete child;

        if (startingNode->getAlpha() > startingNode->getBeta()) {
            return;
        }
    }
}
