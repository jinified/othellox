#ifndef __COMMON_H__
#define __COMMON_H__

#include <string>
#include <string.h>
#include <sstream>

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

    std::string getPos() {
        char col = "abcdefghijklmnopqrstuvwxyz"[x-1];
        std::stringstream ss;
        ss << col << y;
        return ss.str();
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
    Side maximizer;
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
        maximizer = *player == 'W' ? WHITE : BLACK;
    }

    void printInfo() {
        printf("\n/** GAME INFO **/\nBoard size: %d,%d\nPlayer: %s\nWhite Pos: %s\nBlack Pos: %s\nTimeout: %d\n",
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
        printf("\n/** EVAL INFO **/\nMax depth: %d\nMax nodes: %d\nCorner value: %d\nEdge value: %d\n",
               maxDepth, maxNodes, cornerValue, edgeValue);
    }
};

/*
 * Transposition table entry
 */
class TableEntry {

public:
    int alpha, beta, depth;
    Move *move;
    TableEntry() {}
    TableEntry(Move *move, int alpha, int beta, int depth) {
        this->move = move;
        this->alpha = alpha;
        this->beta = beta;
        this->depth = depth; // Depth of tree which gave this value
    }
};

#endif
