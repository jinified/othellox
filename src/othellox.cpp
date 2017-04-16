#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <time.h>
#define BOARD_SIZE 8
#define WHITE 1
#define BLACK 2
#define ABDEPTH 6

// MPI declarations
int myrank;
int name_len;
char processor_name[MPI_MAX_PROCESSOR_NAME];

void usage() {
	fprintf(stderr,"USAGE: ./othello <initial board file> <evaluation parameters file>\n");
}


int main(int argc, char **argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
    // Get rank of process
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	// Get the name of the processor
    MPI_Get_processor_name(processor_name, &name_len);
	printf("Hello world from processor %s, rank %d\n", processor_name, myrank);

	if(argc != 3) {
		usage();
		return EXIT_FAILURE;
	}
	MPI_Finalize();
    return 0; 
}
