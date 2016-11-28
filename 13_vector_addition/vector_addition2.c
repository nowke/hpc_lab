#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int *a, *b, *c, processors, rank;
    long n_per_proc;
    long i, N;

    //MPI_Status status;
    MPI_Init (&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &processors);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int *ap, *bp, *cp;
    double t1, t2;

    N = atol(argv[1]);
    n_per_proc = N/processors;

    if(N % processors != 0)
        n_per_proc++;

    a = (int *) malloc(sizeof(int) * N);
    b = (int *) malloc(sizeof(int) * N);
    c = (int *) malloc(sizeof(int) * N);

    for (i=0; i<N; i++)
        a[i] = b[i] = i;

    ap = (int *) malloc(sizeof(int)*n_per_proc);
    bp = (int *) malloc(sizeof(int)*n_per_proc);
    cp = (int *) malloc(sizeof(int)*n_per_proc);

    if (rank == 0) {
        t1 = MPI_Wtime();
    }

    MPI_Scatter(a, n_per_proc, MPI_INT, ap, n_per_proc, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(b, n_per_proc, MPI_INT, bp, n_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    for(i=0; i < n_per_proc; i++)
        cp[i] = ap[i] + bp[i];

    MPI_Gather(cp, n_per_proc, MPI_INT, c, n_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        t2 = MPI_Wtime();
        // for (i=0;i<N;i++) {
        //     printf("%d ",c[i]);
        // }
        // printf("\n");
        printf("Elapsed time is %lfms\n", (t2 - t1) * 1000);
    }

    MPI_Finalize();
    return 0;
}
