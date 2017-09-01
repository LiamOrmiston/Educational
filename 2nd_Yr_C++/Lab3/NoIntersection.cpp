#include <stdexcept>
#include <string>
#include "NoIntersection.h"

//Exception class for Negative Discriminant
//If it is called, then it will give a message to the catch
NoIntersection::NoIntersection(): std::runtime_error("No intersection")
{

}
