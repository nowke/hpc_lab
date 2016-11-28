#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32

char* messages[3] = {"Hello World", "Hello CSE", "Hello MPI"};

int main(int argc, char *argv[]) {
    int rank, processors, desination;
    int tag=0, root=0, temp=1;
    char message[BUFFER_SIZE];
    MPI_Status status;

    MPI_Init(&argc, &argv); // Initializes MPI

    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Rank (or Task ID) is stored in `rank`
    MPI_Comm_size(MPI_COMM_WORLD, &processors); // Communicator size = No.of Processors

    if (rank == 0) {
        for (temp = 1; temp<processors; temp++) {
            MPI_Recv(message, BUFFER_SIZE, MPI_CHAR, temp, tag, MPI_COMM_WORLD, &status);
            printf("%s in process with rank 0 from Process with rank %d\n", message, temp);
        }
    } else {
        strcpy(message, messages[(rank-1) % 3]);
        MPI_Send(message, BUFFER_SIZE, MPI_CHAR, 0, tag, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}
