#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define PI 3.1415926538837211

int main(int argc, char* argv[]) {
    int i, intervals;
    double x, totalsum, h;

    intervals = atoi(argv[1]);
    
    omp_set_num_threads(atoi(argv[2]));

    totalsum = 0.0;
    h = 1.0 / intervals;
    double t1 = omp_get_wtime();
    
    #pragma omp parallel for private(x) reduction(+:totalsum)
    for (i=1; i<intervals; i++) {
        x = h * (i+0.5);
        totalsum =totalsum + 4.0 / (1.0 + x * x);
    }

    totalsum = totalsum * h;
    double t2 = omp_get_wtime();


    printf("\nActual PI: %1.15lf\n", PI);
    printf("Calculated PI: %1.15lf\n", totalsum);
    printf("Error: %1.15lf\n", fabs(totalsum - PI));

    printf("Time taken: %lf ms\n", (t2 - t1)*1000);
    return 0;
}   