#include "Blob.h"

Blob::~Blob() {
  std::cout << "Blob Destructor\n";
}

Blob::Blob(double area, string color)
  :ColoredShape(color)
{
  a = area;
}

double
Blob::getArea(void) {
  return a;
}


