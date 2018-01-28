#include <stdexcept>
#include <string>
#include "CannotDetermineRoomDimensions.h"

//Declares exception class for room dimensions
//If called, it will pass a message to the catch
CannotDetermineRoomDimensions::CannotDetermineRoomDimensions(): std::runtime_error("Cannot determine room dimensions")
{

}
