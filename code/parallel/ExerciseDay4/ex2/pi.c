#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

static long int numSteps = 10000000;

double mpi = 3.1415926535897932384626433832795;

int main() {

  // perform calculation
  double pi   = 0;
  double dx = 1./numSteps;
  double x  = dx*0.50;
    
#pragma omp parallel reduction(+:pi)
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    double myPart = 0.;
    for (int i=tid; i<numSteps; i+= numT){
      x = ((double) i + .5) / ((double) numSteps);
      myPart += 4./(1.+x*x);
    }
      

    pi += myPart;
  }

  pi *= dx;


  printf("PI = %16.14f Difference from math.h definition %16.14f \n",pi, pi-mpi);
  return 0;
}
