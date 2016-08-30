#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<omp.h>

#define PI 3.1415926538837211

int main(int argc, char* argv[]) {
  double pi, x, y, z;
  int intervals, i, count=0;

  printf("Enter no. of intervals: ");
  scanf("%d", &intervals);

  #pragma omp parallel for
  for (i=0; i<intervals; i++) {
    x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x*x + y*y;
		if (z <= 1) count++;
  }
  pi=(double)count/ intervals * 4;

  printf("\nAcutal PI: %1.15lf\n", PI);
  printf("Calculated PI: %1.15lf\n", pi);
  printf("Error: %1.15lf\n", fabs(pi - PI));
}
