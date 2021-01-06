#ifndef _TRIANGLE
#define _TRIANGLE

#include "ColoredShape.h"

class Triangle: public ColoredShape {
 public:
  Triangle(double side, string color);
  ~Triangle();
  double getHeight(void);

};

#endif // _TRIANGLE

  
