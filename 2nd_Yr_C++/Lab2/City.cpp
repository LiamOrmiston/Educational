#include "City.h"
#include <iostream>
#include <fstream>
#include <string>

City::City(std::string Name, int Pop, int Level)
{
  c_Name = Name;
  c_Pop = Pop;
  c_Level = Level;
}

void City::setName (std::string Name)
{
    c_Name = Name;
}

void City::setPop (int Pop)
{
    c_Pop = Pop;
}

void City::setLevel (int Level)
{
    c_Level = Level;
}

std::string City::getName()
{
  return (c_Name);
}

int City::getPop ()
{
  return (c_Pop);
}

int City::getLevel ()
{
  return (c_Level);
}
