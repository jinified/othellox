#ifndef __BOARD_H__
#define __BOARD_H__

#include "common.h"
#include <vector>
#include <cstddef>

#define CORNER_WEIGHT 50
#define MOVES_WEIGHT 2 // # moves cur_player - # moves opp_player
#define DIAGONAL_WEIGHT -10
#define EDGE_WEIGHT 5
#define FRONTIER_WEIGHT 2
#define MAX_BOARD_SIZE 676

using namespace std;

class Board {

private:
    bool occupied(int x, int y);
    bool get(Side side, int x, int y);
    void set(Side side, int x, int y);
    bool onBoard(int x, int y);

public:
    Board(int, int);
    ~Board();
    vector<int> black = vector<int>(MAX_BOARD_SIZE);
    vector<int> taken = vector<int>(MAX_BOARD_SIZE);
    int row;
    int col;
    int size;
    Board *copy();

    bool isDone();
    bool hasMoves(Side side);
    bool checkMove(Move *m, Side side);
    vector<Move> getMoves(Side side);
    void doMove(Move *m, Side side);
    void printBoard();
    int count(Side side);
    int countBlack();
    int countWhite();
    int getScore(Side maximizer);

    int boolToInt(bool b);
    int getMovesScore(Side maximizer);
    int getFrontierScore(Side maximizer);
};

#endif
