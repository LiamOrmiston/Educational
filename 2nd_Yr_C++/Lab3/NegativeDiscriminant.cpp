#include <stdexcept>
#include <string>
#include "NegativeDiscriminant.h"

//Exception class for Negative Discriminant
//If it is called, then it will give a message to the catch 
NegativeDiscriminant::NegativeDiscriminant(): std::runtime_error("No real solutions")
{
}
