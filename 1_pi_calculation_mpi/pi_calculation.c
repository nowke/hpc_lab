#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1415926538837211

int main(int argc, char* argv[]) {
    int iterations = atoi(argv[1]);
    int i, count=0, reduced_count, reduced_iterations, rank;
    double x, y, z, calculated_pi;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Perform PI calculation in all processes (except rank=0)
    if (rank > 0) {
        srand48(time(NULL));
        for (i=0; i < iterations; i++) {
            x = (double) drand48();
            y = (double) drand48();
            z = x*x + y*y;
            if (z <= 1) {
                count++; // Point is inside the circle
            }
        }
    }

    // Sum all `count` from all processes into `reduced_count`
    MPI_Reduce(&count, &reduced_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    // Sum all `iterations` from all processes into `reduced_iterations`
    MPI_Reduce(&iterations, &reduced_iterations, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    reduced_iterations = reduced_iterations - iterations; // Ignoring master process (rank = 0)

    if (rank == 0) {
        calculated_pi = ((double)reduced_count / (double)reduced_iterations) * 4.0;
        printf("\nActual PI: %1.15lf\n", PI);
        printf("Calculated PI: %1.15lf\n", calculated_pi);
    }

    MPI_Finalize();
    return 0;
}
