// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaX-sigmaY) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take 4 inputs: sigmaX, sigmaY, tauXY, theta
// output transformed stresses: sigmaX', sigmaY', tauXY'
//
// NOTE: perform the transformation inside a function that cannot be named main


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void transform_stresses(float sigmaX, float sigmaY, float tauXY, float angle, float *sigmaXt, float *sigmaYt, float *tauXYt);

int main(int argc, char **argv) {

  if (argc != 5) {
    printf("Usage: appName sigmaX sigmaY tauXY angle\n");
    exit(-1);
  }

  // Input variables
  float sigmaX = atof(argv[1]);
  float sigmaY = atof(argv[2]);
  float tauXY = atof(argv[3]);
  float angle = atof(argv[4]);

  // Internal variables
  float sigmaXt;
  float sigmaYt;
  float tauXYt;

  // perform transformation
  transform_stresses(sigmaX, sigmaY, tauXY, angle, &sigmaXt, &sigmaYt, &tauXYt);

  // output results
  printf("%f, %f, %f\n", sigmaXt, sigmaYt, tauXYt);
  return 0;
}

// function to perform the transformation
void transform_stresses(float sigmaX, float sigmaY, float tauXY, float angle, float *sigmaXt, float *sigmaYt, float *tauXYt) {
  float pi = 3.14159265358979323846;
  float ang_rad = angle / 180. * pi;
  *sigmaXt = sigmaX * cos(ang_rad) * cos(ang_rad) + sigmaY * sin(ang_rad) * sin(ang_rad) + 2 * tauXY * sin(ang_rad) * cos(ang_rad);
  *sigmaYt = sigmaX * sin(ang_rad) * sin(ang_rad) + sigmaY * cos(ang_rad) * cos(ang_rad) - 2 * tauXY * sin(ang_rad) * cos(ang_rad);
  *tauXYt = (sigmaX - sigmaY) * sin(ang_rad) * cos(ang_rad) + tauXY * (cos(ang_rad) * cos(ang_rad) - sin(ang_rad) * sin(ang_rad));
}
