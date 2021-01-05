// program to solve quadratic equation
//        ax^2 + bx + c = 0
//
// soln: x = -b/2a +/- sqrt(b^2-4ac)/2a
//
// write a program to take 3 inputs and output the soln
// deal with possible errors in input, i.e. b^2-4ac negative

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: appName a b c\n");
    exit(-1);
  }

  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = atof(argv[3]);
  float res1;
  float res2;

  float x = b*b - 4*a*c;

      if (x < 0.00) {
        printf("No real solution\n");
        exit(-1);
      }

      x = sqrt(x);
      res1 = (b+x)/(2.00*a);
      res2 = (b-x)/(2.00*a);

      printf("Root1: %f\nRoot2: %f\n", res1, res2);
    return 0;
}
