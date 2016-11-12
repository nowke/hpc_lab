#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32

int main(int argc, char *argv[]) {
    int rank, processors, desination;
    int tag=0, root=0, temp=1;
    char message[BUFFER_SIZE];
    MPI_Status status;

    MPI_Init(&argc, &argv); // Initializes MPI

    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Rank (or Task ID) is stored in `rank`
    MPI_Comm_size(MPI_COMM_WORLD, &processors); // Communicator size = No.of Processors

    // Task 0 (Rank = 0) sends message `Hello World` to all the other processors

    if (rank == 0) {
        system("hostname");
        strcpy(message, "Hello World");
        // Send to all processsors
        for (temp=1; temp<processors; temp++) {
            MPI_Send(message, BUFFER_SIZE, MPI_CHAR, temp, tag, MPI_COMM_WORLD);
        }
    } else {
        system("hostname");
        MPI_Recv(message, BUFFER_SIZE, MPI_CHAR, root, tag, MPI_COMM_WORLD, &status);
        printf("\n%s in process with rank %d from Process with rank %d\n", message, rank, root);
    }

    MPI_Finalize();
}
