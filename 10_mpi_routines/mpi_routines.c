#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32

int main(int argc, char *argv[]) {
    int rank, processors, desination;
    int tag=0, root=0, temp=1;
    char message[BUFFER_SIZE];
    MPI_Init(&argc, &argv);
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &processors);

    if (rank == 0) {
        system("hostname");
        strcpy(message, "Hello World");
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
