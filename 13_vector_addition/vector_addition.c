#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int N = atoi(argv[1]);
    int i, j, processes, rank, N_per_process, tag=100;
    MPI_Status status;
    int *A = (int *) malloc(sizeof(int) * N);
    int *B = (int *) malloc(sizeof(int) * N);
    int *C = (int *) malloc(sizeof(int) * N);

    int *AP, *BP, *CP;
    int *buff;

    for (i=0; i<N; i++) {
        A[i] = i;
        B[i] = i;
    }

    MPI_Init (&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &processes);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    N_per_process = N / processes;
    buff = (int *) malloc(sizeof(int) * N_per_process);

    if (rank == 0) {
        for (i=0; i<processes-1; i++) {
            // Divided A & B and send it to other processes evenly
            for (j=0; j<N_per_process; j++) {
                buff[j] = A[(N_per_process * i) +j];
            }
            MPI_Send(buff, N_per_process, MPI_INT, i+1, tag, MPI_COMM_WORLD);

            for (j=0; j<N_per_process; j++) {
                buff[j] = B[(N_per_process * i) +j];
            }
            MPI_Send(buff, N_per_process, MPI_INT, i+1, tag, MPI_COMM_WORLD);
        }

        // Receive C from other processes in pieces & combine
        for (i=0; i<processes-1; i++) {
            MPI_Recv(buff, N_per_process, MPI_INT, i+1, tag, MPI_COMM_WORLD, &status);
            for (j=0; j<N_per_process; j++) {
                C[(N_per_process * i) + j] = buff[j];
            }
        }

        // Remaining part of Vector
        for (int i=N - N_per_process; i < N; i++) {
            C[i] = A[i] + B[i];
        }
        // for (i=0; i<N; i++) {
        //     printf("%d, ", C[i]);
        // }
        // printf("\n");
    } else {
        AP = (int *) malloc(sizeof(int) * N_per_process);
        BP = (int *) malloc(sizeof(int) * N_per_process);
        CP = (int *) malloc(sizeof(int) * N_per_process);

        MPI_Recv(AP, N_per_process, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
        MPI_Recv(BP, N_per_process, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);

        for (i=0; i<N_per_process; i++) {
            CP[i] = AP[i] + BP[i];
        }
        MPI_Send(CP, N_per_process, MPI_INT, 0, tag, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
