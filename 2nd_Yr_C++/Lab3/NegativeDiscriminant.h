#ifndef NEGATIVEDISCRIMINANT_H
#define NEGATIVEDISCRIMINANT_H

#include <stdexcept>
#include <string>

//Declares exception class for Negative Discriminant
class NegativeDiscriminant: public std::runtime_error
{
public:
  NegativeDiscriminant();
};

#endif
