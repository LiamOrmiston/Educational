#ifndef CANNOTDETERMINEROOMDIMENSIONS_H
#define CANNOTDETERMINEROOMDIMENSIONS_H

#include <stdexcept>
#include <string>

//Exception class for room dimensions
class CannotDetermineRoomDimensions: public std::runtime_error
{
public:
  CannotDetermineRoomDimensions();
};
#endif
