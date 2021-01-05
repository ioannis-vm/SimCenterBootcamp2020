// calculate pi numerically
//
// pi = integral 0->1 (4/(1+x^2))dX
//
// compute an approx using sum from i = 1 to N
// of F(xi)delta X, where F(xi) computed at middle of iterval i
//
// take as input the number of intervals N

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Usage: appName numSteps\n");
    exit(-1);
  }

  // Input variables
  int long numSteps = atof(argv[1]);

  // Internal variables
  double pi = 0.;
  double time = 0.;
  double dx = 1./numSteps;
  double x = 0.;
  double F = 0.;
  clock_t start, end;

  start = clock();

  for (int i = 0; i < numSteps-1; i++) {
    x = (((double) i)+.5)/((double) numSteps);
    F = 4./(1.+x*x);
    pi += F;
  }
  pi = pi * dx;

  end = clock();
  time = ((double) (end - start)) / CLOCKS_PER_SEC;

  // output results
  printf("pi = %3.20f, duration: %f ms\n", pi, time);
  return 0;
}
