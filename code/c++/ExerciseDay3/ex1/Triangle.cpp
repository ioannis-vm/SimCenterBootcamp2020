#include "Triangle.h"

Triangle::~Triangle() {
  std::cout << "Triangle Destructor\n";
}

Triangle::Triangle(double side, string color)
  :ColoredShape(color)
{
  b = side;
}

double
Triangle::getHeight(void) {
  return b*0.8660254037844;
}

