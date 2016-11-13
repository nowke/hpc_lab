#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>

double max(double a, double b) {
    return a>b ? a : b;
}

int main() {

    double *T, *Tnew, *Tmp;
    double tol, var = DBL_MAX,var1, top = 100.0;
    int n, n2, maxIter, i, j, iter = 0;
    int itemsread;
    FILE *fout;

    printf("Enter mesh size, max iterations and tolerance: ");
    itemsread = scanf("%u %u %lf", &n, &maxIter, &tol);
    if (itemsread!=3) {
        fprintf(stderr, "Input error!\n");
        exit(-1);
    }

    n2 = n+2;
    T = (double *)calloc(n2*n2, sizeof(*T));
    Tnew = (double *)calloc(n2*n2, sizeof(*T));
    if (T == NULL || Tnew == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    for (i=1; i<=n; i++) {
        T[(n+1)*n2+i] = Tnew[(n+1)*n2+i] = i * top / (n+1);
        T[i*n2+n+1] = Tnew[i*n2+n+1] = i * top / (n+1);
    }

    double startTime = omp_get_wtime();
    #pragma omp parallel
    {
        while(var > tol && iter <= maxIter) {
            #pragma omp barrier
            #pragma omp single
            {
                ++iter;
                var = 0.0;
            }
            #pragma omp for private(j) reduction(max : var)
            for (i=1; i<=n; ++i)
                for (j=1; j<=n; ++j) {
                    Tnew[i*n2+j] = 0.25*(  T[(i-1)*n2+j]
                                         + T[(i+1)*n2+j]
                                         + T[i*n2+(j-1)]
                                         + T[i*n2+(j+1)] );
                    var = max(var, fabs(Tnew[i*n2+j] - T[i*n2+j]));
                }
            #pragma omp single nowait
            {
                Tmp=T; T=Tnew; Tnew=Tmp;
                if (iter%100 == 0)
                    printf("iter: %8u, variation = %12.4lE\n", iter, var);
            }
        }
    }
    double endTime = omp_get_wtime() - startTime;

    printf("Elapsed time (s) = %lf\n", endTime);///
    printf("Mesh size: %u\n", n);
    printf("Stopped at iteration: %u\n", iter);
    printf("Maximum error: %lE\n", var);

    double flops = 2.0 * iter * (0.5 *n *(log(n)/log(2)));

    // MFLOPS = flops/1000000/time
    double mflops = flops / 1000000 / (endTime);
    printf("Flops: %lf\n", flops);
    printf("mflos: %lf\n", mflops);
}
