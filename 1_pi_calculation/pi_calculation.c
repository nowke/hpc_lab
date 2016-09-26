#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define PI 3.1415926538837211

int intervals, num_threads;

double calculate_pi() {
  double totalsum = 0.0;
  double h = 1.0 / intervals;
  double x;
  int i;

  #pragma omp parallel for private(x) reduction(+:totalsum)
  for (i=1; i < intervals; i++) {
      x = h * (i+0.5);
      totalsum = totalsum + 4.0 / (1.0 + x * x);
  }

  totalsum = totalsum * h;
  return totalsum;
}

int main(int argc, char const *argv[]) {

    intervals = atoi(argv[1]);
    num_threads = atoi(argv[2]);

    omp_set_num_threads(num_threads);

    double T1 = omp_get_wtime();
    double PI_RESULT = calculate_pi();
    double T2 = omp_get_wtime();

    printf("\nActual PI: %1.15lf\n", PI);
    printf("Calculated PI: %1.15lf\n", PI_RESULT);
    printf("Error: %1.15lf\n", fabs(PI_RESULT - PI));

    printf("Time taken: %lf ms\n", (T2 - T1) * 1000);
    return 0;
}
