#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "MathTools.h"
#include <string>

class Executive
{
  public:
    Executive();
    void run();
    double isDouble();

  private:
    MathTools math;

//Declares everything used in the executive.cpp
    std::string choice;
    int num;

    double d;
    double e;
    double f;
    double xy[2][2];

    double Area;
    double Extra;
    double minRequiredLength;
    double width;
    double length;

    double a;
    double b;
    double c;
    double roots[2];
};
#endif
