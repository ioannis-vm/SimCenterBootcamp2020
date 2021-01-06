#ifndef _BLOB
#define _BLOB

#include "ColoredShape.h"

class Blob: public ColoredShape {
 public:
  Blob(double a, string color);
  ~Blob();
  double getArea(void);

 protected:

 private:
  double a;
};

#endif // _BLOB

  
