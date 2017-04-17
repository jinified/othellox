#include <mpi.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>

#include "common.h"
#include "board.h"
#include "gametree.h"

#define MAX_CHAR_IN_LINE 128
#define MAX_POSLIST 2704

using namespace std;

// MPI declarations
int myrank;
int name_len;
char processor_name[MPI_MAX_PROCESSOR_NAME];

// Utilities

void arginfo(char *boardpath, char *evalparamspath) {
    printf("Board: %s\nEvalparams: %s\n", boardpath, evalparamspath);
}

void usage() { fprintf(stderr,"USAGE: ./othello <initial board file> <evaluation parameters file>\n");
}

// Input / Output

GameInfo *parse_board(char *filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_CHAR_IN_LINE];
    char white_pos[MAX_POSLIST];
    char black_pos[MAX_POSLIST];
    char player[MAX_POSLIST];
    int x, y, timeout;

    if (file == NULL) {
        perror("Error opening file");
    } else {

        while((fgets(line, MAX_CHAR_IN_LINE, file) != NULL)) {
            sscanf(line, "Size: %d,%d %*s", &x, &y);
            sscanf(line, "White: { %s } %*s", white_pos);
            sscanf(line, "Black: { %s } %*s", black_pos);
            sscanf(line, "Color: %s %*s", player);
            sscanf(line, "Timeout: %d %*s", &timeout);
        }
        fclose(file);
    }
    GameInfo *info = new GameInfo(x, y, player, white_pos, black_pos, timeout);
    return info;
}

EvalInfo *parse_evalparams(char *filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_CHAR_IN_LINE];
    int maxDepth, maxNodes, cornerValue, edgeValue;

    if (file == NULL) {
        perror("Error opening file");
    } else {

        while((fgets(line, MAX_CHAR_IN_LINE, file) != NULL)) {
            sscanf(line, "MaxDepth: %d %*s", &maxDepth);
            sscanf(line, "MaxBoards: %d %*s", &maxNodes);
            sscanf(line, "CornerValue: %d %*s", &cornerValue);
            sscanf(line, "EdgeValue: %d %*s", &edgeValue);
        }
        fclose(file);
    }
    EvalInfo *info = new EvalInfo(maxDepth, maxNodes, cornerValue, edgeValue);
    return info;
}

// Solver routine

vector<Move> iterativeDeepening(Side side, Board *board, int maxDepth, int maxNodes,
                                int timeout) {
    vector<Move> moves;
    GameTree *tree = new GameTree(board->copy(), side, maxDepth, maxNodes, timeout);
    for (int i=1; i < maxDepth; i++) {
        Move *bestmove = tree->findBestMove(i, true);
        moves.push_back(*bestmove);
    }
}

void simulate(int rounds, Board *board, int depth, int maxDepth, int maxNodes,
              int timeout) {
    // Simulate an othello game using our program for both players

    for (int i=0; i < rounds; i++) {
        Move *bestmove;
        if (i % 2 == 0) {
            GameTree *tree = new GameTree(board->copy(), BLACK,
                                          maxDepth, maxNodes, timeout);
            bestmove = tree->findBestMove(depth, true);
            board->doMove(bestmove, BLACK);
        } else {
            GameTree *tree = new GameTree(board->copy(), WHITE,
                                          maxDepth, maxNodes, timeout);
            bestmove = tree->findBestMove(depth, true);
            board->doMove(bestmove, WHITE);
        }
    }
}

// Main program

int main(int argc, char **argv) {

    if (argc != 3) {
        usage();
        return EXIT_FAILURE;
    } else {
        // Initialize the MPI environment
        MPI_Init(NULL, NULL);
        // Get rank of process
        MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
        // Get the name of the processor
        MPI_Get_processor_name(processor_name, &name_len);

        // Master process in charge of parsing
        if (myrank == 0) {
            // Parses config files
            GameInfo *game_info = parse_board(argv[1]);
            // game_info->printInfo();
            EvalInfo *eval_info = parse_evalparams(argv[2]);
            // eval_info->printInfo();

            // Initialize board
            Board *board = new Board(game_info->row, game_info->col);
            board->setupBoard(game_info->white_pos, game_info->black_pos);

            // Initializes evaluation parameters
            board->corner_weight = eval_info->cornerValue;
            board->edge_weight = eval_info->edgeValue;

            // Solving code

            GameTree *tree = new GameTree(board->copy(), game_info->maximizer,
                                          eval_info->maxDepth, eval_info->maxNodes,
                                          game_info->timeout);
            Move *bestmove = tree->findBestMove(eval_info->maxDepth, true);
            // Initialize simulator for testing
            // simulate(10, board, 6, eval_info->maxDepth, eval_info->maxNodes, game_info->timeout);
            // iterativeDeepening(BLACK, board, eval_info->maxDepth,
            //                    eval_info->maxNodes, 30);
        } else {
            printf("Hello from processor %s", processor_name);
        }
    }
	MPI_Finalize();
    return 0;
}
