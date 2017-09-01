#ifndef NOINTERSECTION_H
#define NOINTERSECTION_H

#include <stdexcept>
#include <string>

//Declares exception class for No Intersection 
class NoIntersection: public std::runtime_error
{
public:
  NoIntersection();
};
#endif
