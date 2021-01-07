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

#include <mpi.h>
#define LUMP 5

int main(int argc, char **argv) {

  if (argc != 1) {
    printf("Usage: appName\n");
    exit(-1);
  }

  double time = 0.;
  double pi = 0.;
  clock_t start, end;
  start = clock();


  // the usual mpi initialization
  int numP, procID;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  int *globalData=NULL;
  int localData[LUMP];

  int long numSteps = LUMP * numP;
  double dx = 1./numSteps;
  double x = 0.;

  // process 0 is only 1 that needs global data
  if (procID == 0) {
    globalData = malloc(LUMP * numP * sizeof(double) );
  }

  for (int i=0; i<LUMP; i++) {
    x = ((double) procID + i + .5) / ((double) numSteps);
    localData[procID + i] = 4./(1.+x*x);
  }


  MPI_Gather(localData, LUMP, MPI_DOUBLE, globalData, LUMP, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  if (procID == 0) {
    for (int i=0; i<numP*LUMP; i++) {
      pi += globalData[i];
    }
    pi = pi * dx;
  }

  if (procID == 0)
    free(globalData);

  MPI_Finalize();

  end = clock();

  time = ((double) (end - start)) / CLOCKS_PER_SEC;

  // output results
  printf("pi = %3.20f, duration: %f ms\n", pi, time);
  return 0;
}
