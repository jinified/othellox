#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "common.h"

#define MAX_CHAR_IN_LINE 128
#define MAX_POSLIST 2704

using namespace std;

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

int main(int argc, char **argv) {
    if (argc != 3) {
        usage();
        return EXIT_FAILURE;
    } else {
        arginfo(argv[1], argv[2]);
        GameInfo *game_info = parse_board(argv[1]);
        game_info->printInfo();
        EvalInfo *eval_info = parse_evalparams(argv[2]);
        eval_info->printInfo();
    }
    return 0;
}
