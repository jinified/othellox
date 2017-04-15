#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <time.h>
#define MAX_CHAR_IN_LINE 128
#define MAX_BOARD 26
#define MAX_POSLIST 2704
#define WHITE 1
#define BLACK 2
#define ABDEPTH 6


// Common structs

typedef struct boardinfo_ {
    int row;
    int col;
    int timeout;
    int** bboard;
    char *player;
} board_info;

typedef struct evalinfo_ {
    int max_depth;
    int max_n_boards;
    int corner_value;
    int edge_value;
} eval_info;

// Input / Output

board_info parse_board(char *filename) {
    FILE* file = fopen(filename, "r");
    // Dynamic 2D array creation
    int **board;
    char line[MAX_CHAR_IN_LINE];
    char white_pos[MAX_POSLIST];
    char black_pos[MAX_POSLIST];
    char *player;
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

    // Initializes board
    board = malloc(y * sizeof(int*));
    for (int i = 0; i < y; i++) {
        board[i] = (int*) malloc(x * sizeof(int));
    }

    for (int i=0; i < y; i++) {
        for (int j=0; j < x; j++) {
            board[i][j] = 0;
        }
    }

    // Parse white board positions
    char *pt = strtok(white_pos, ",");
    while(pt != NULL) {
        int col = (*pt - 'a');
        int row = (*(pt+1) - '0') - 1;
        board[row][col] = 1;
        pt = strtok (NULL, ",");
    }

    // Parse black board positions
    pt = strtok(black_pos, ",");
    while(pt != NULL) {
        int col = (*pt - 'a');
        int row = (*(pt+1) - '0') - 1;
        board[row][col] = 2;
        pt = strtok (NULL, ",");
    }

    // Initializes board info
    board_info info;
    info.row = y;
    info.col = x;
    info.timeout = timeout;
    info.player = player;
    info.bboard = board;
    return info;
}

eval_info parse_evalparams(char *filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_CHAR_IN_LINE];

    // Initialize evaluation parameters info
    eval_info info;

    if (file == NULL) {
        perror("Error opening file");
    } else {

        while((fgets(line, MAX_CHAR_IN_LINE, file) != NULL)) {
            sscanf(line, "MaxDepth: %d %*s", &info.max_depth);
            sscanf(line, "MaxBoards: %d %*s", &info.max_n_boards);
            sscanf(line, "CornerValue: %d %*s", &info.corner_value);
            sscanf(line, "EdgeValue: %d %*s", &info.edge_value);
        }
        fclose(file);
    }
    return info;
}

void usage() {
	fprintf(stderr,"USAGE: ./othello <initial board file> <evaluation parameters file>\n");
}

// Visualize data

void print_board(int** board, int row, int col) {
    for (int i=0; i < row; i++) {
        for (int j=0; j < col; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void print_board_info(board_info info) {
    printf("// Board data\n\nBoard size: %d x %d\n\n", info.row, info.col);
    print_board(info.bboard, info.row, info.col);
}

void print_evalparams_info(eval_info info) {
    printf("\n// Eval params data\n\n");
    printf("Max Depth: %d\n", info.max_depth);
    printf("Max No of boards: %d\n", info.max_n_boards);
    printf("Corner value: %d\n", info.corner_value);
    printf("Edge value: %d\n", info.edge_value);
}

void clear_board(int** board, int row) {
    for (int i=0; i < row; i++) {
        free(board[i]);
    }
    free(board);
}

int main(int argc, char **argv) {
	if(argc != 3) {
		usage();
		return EXIT_FAILURE;
	}

    // Parse input files
    board_info board_data = parse_board(argv[1]);
    eval_info eval_data = parse_evalparams(argv[2]);

    // Visualize data
    print_board_info(board_data);
    print_evalparams_info(eval_data);

    // Cleaning up
    clear_board(board_data.bboard, board_data.row);

    return 0; 
}
