#ifndef __COMMON_H__
#define __COMMON_H__

#include<string>

enum Side {
    BLACK, WHITE
};

class Move {

public:
    int x, y;
    Move(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() { return x; }
    int getY() { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
};

/*
 * Stores game related configuration
*/
class GameInfo {

public:
    int row, col;
    char *player;
    char *white_pos;
    char *black_pos;
    int timeout;

    GameInfo(int row, int col, char *player, char *white_pos, char *black_pos, int timeout) {
        this->row = row;
        this->col = col;
        this->player = player;
        this->white_pos = white_pos;
        this->black_pos = black_pos;
        this->timeout = timeout;
    }

    void printInfo() {
        printf("Board size: %d,%d\nPlayer: %s\nWhite Pos: %s\nBlack Pos: %s\nTimeout: %d\n",
               row, col, player, white_pos, black_pos, timeout);
    }
};

/*
 * Stores evaluation parameters
*/
class EvalInfo {

public:
    int maxDepth, maxNodes, cornerValue, edgeValue;
    EvalInfo(int maxDepth, int maxNodes, int cornerValue, int edgeValue) {
        this->maxDepth = maxDepth;
        this->maxNodes = maxNodes;
        this->cornerValue = cornerValue;
        this->edgeValue = edgeValue;
    }

    void printInfo() {
        printf("Max depth: %d\nMax nodes: %d\nCorner value: %d\nEdge value: %d\n",
               maxDepth, maxNodes, cornerValue, edgeValue);
    }
};
#endif
