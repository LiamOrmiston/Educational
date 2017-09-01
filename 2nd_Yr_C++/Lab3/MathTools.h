#ifndef MATHTOOLS_H
#define MATHTOOLS_H
#include "MathToolsInterface.h"

class MathTools
{
public:
//Declares all the MathTools Methods

  int intersectLineUnitCircle(double d, double e, double f, double xy[2][2]) throw (NoIntersection);

  void roomDimensions(double Area, double Extra, double minRequiredLength, double& width, double& length) throw (CannotDetermineRoomDimensions);

  int solveQuadratic(double a, double b, double c, double roots[2]) throw (NegativeDiscriminant);

  double xval (double d, double e, double f, double yVal);
};
#endif
