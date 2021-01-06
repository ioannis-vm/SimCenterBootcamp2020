#include <stdio.h>
#include <stdlib.h>
#include "stresstransform.h"


int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Usage: appName increment\n");
    exit(-1);
  }

  // Input variables
  float increment = atof(argv[1]);

  // Internal variables
  STRESS S0;
  STRESS Sp;
  float angle = 0;

  S0.sigx = 12.0;
  S0.sigy = -5.5;
  S0.tau  =  3.5;

  while (angle <= 180.) {
    StressTransform(S0, &Sp, angle);
    printf("%12.6f, %12.6f, %12.6f\n", Sp.sigx, Sp.sigy, Sp.tau);
    angle += increment;
  }

}
