#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int matrix_size, num_threads;
int **A, **B, **C;

void allocate_matrix() {
  int i, j, num=0;

  // Allocate Memory
  A = (int **) malloc(matrix_size * sizeof(int *));
  B = (int **) malloc(matrix_size * sizeof(int *));
  C = (int **) malloc(matrix_size * sizeof(int *));

  for (i=0; i < matrix_size; i++) {
    A[i] = (int *) malloc(matrix_size * sizeof(int));
    B[i] = (int *) malloc(matrix_size * sizeof(int));
    C[i] = (int *) malloc(matrix_size * sizeof(int));
  }

  // Initialize with some values
  for (i=0; i < matrix_size; i++) {
    for (j=0; j < matrix_size; j++) {
      A[i][j] = num++;
      B[i][j] = num++;
    }
  }
}

void multiply_matrix() {

  #pragma omp parallel
  {
    int i, j, k;

    #pragma omp for
    for (i=0; i < matrix_size; i++) {
      for (j=0; j < matrix_size; j++) {
        C[i][j] = 0;
        for (k=0; k < matrix_size; k++) {
          C[i][j] += B[i][k] * C[k][j];
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {

  matrix_size = atoi(argv[1]);
  num_threads = atoi(argv[2]);

	omp_set_num_threads(num_threads);
  allocate_matrix();

  double T1 = omp_get_wtime();
  multiply_matrix();
  double T2 = omp_get_wtime();

  printf("Time Taken: %lf ms\n", (T2 - T1) * 1000);

  return 0;
}
