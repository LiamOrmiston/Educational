#include "MathTools.h"
#include <iostream>
#include <string>
#include <cmath>

//Takes in 4 doubles, last one being the x coordinates and solves to find the y coordinates
double MathTools::xval (double d, double e, double f, double yValues)
{
  double temp = (-f - (e * yValues)) / d;
  return (temp);
}

//Solve Intersect Line takes in 3 doubles, a 2D array of doubles, and initiates the exception class
int MathTools::intersectLineUnitCircle(double d, double e, double f, double xy[2][2]) throw (NoIntersection)
{
  try
  {
    double a = (d*d + e*e);
    double b = (2 * e * f);
    double c = (f * f - d * d);

    int points = 0;
    double yValues [2];

    points = solveQuadratic(a, b, c, yValues);

//set the x and y coordinates in the 2D array.
    for (int i = 0; i < points; i++)
    {
      xy[0][i] = xval(d, e, f, yValues[i]);
      xy[1][i] = yValues[i];
    }

//returns how many points of intersection there are
    return (points);
  }
  catch (NegativeDiscriminant e)
  {
    throw NoIntersection();
  }
}

//Room Dimensions takes in 5 doubles, last two are references and initiates the exception class
void MathTools::roomDimensions(double Area, double Extra, double minRequiredLength, double& width, double& length) throw (CannotDetermineRoomDimensions)
{
  double roots[2];
  int n_roots = 0;
  try
  {
    n_roots = solveQuadratic(1, Extra, -Area, roots);

//if there is one solution and is greater or equal to the the minimum value, then that is the length.
    if(n_roots == 1 && roots[0] >= minRequiredLength)
    {
      length = roots[0];
      width = length + Extra;
    }

//if there are two solutions, checks to see which is greater or equal to the the minimum value,
//then set that as the length.
    else if (n_roots == 2)
    {
      if(roots[0] >= minRequiredLength)
      {
        length = roots[0];
        width = length + Extra;
      }
      if(roots[1] >= minRequiredLength)
      {
        length = roots[1];
        width = length + Extra;
      }
    }
  }
  catch (NegativeDiscriminant e)
  {
    throw CannotDetermineRoomDimensions();
  }
}

//Solve Quadratic takes in 3 doubles, an array of doubles, and initiates the exception class
int MathTools::solveQuadratic(double a, double b, double c, double roots[]) throw (NegativeDiscriminant)
{
  //if determinate is greater than 0 then there is 2 solutions
    if((b * b - (4 * a * c)) > 0)
    {
      int x = 2;

//quadratic formula
      double x1 = ((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
      double x2 = ((-b - sqrt(b * b - 4 * a * c)) / (2 * a));

//sets solutions to the array
      roots[0] = x1;
      roots[1] = x2;

      return (x);

    }
    //if determinate is equal to 0 then there are 1 solution
    else if ((b * (b - 4 * a * c)) == 0)
    {
      int x = 1;
//quadratic forumla
      double x1 = (-b / (2 * a));
      roots[0] = x1;

      return (x);
    }
    else
    {
      throw NegativeDiscriminant();
    }
}
