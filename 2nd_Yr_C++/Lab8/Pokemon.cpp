#include "Pokemon.h"

Pokemon::Pokemon(std::string name_A, std::string num, std::string name_J)
{
  A_name = name_A;
  dex = num;
  J_name = name_J;
}

bool Pokemon::operator<(const std::string& rhs)
{
  return(strcasecmp(A_name.c_str(), rhs.c_str()) < 0);
}

bool Pokemon::operator<(const Pokemon& rhs)
{
  return(strcasecmp(A_name.c_str(), rhs.getAName().c_str()) < 0);
}

bool Pokemon::operator>(const std::string& rhs)
{
  return(strcasecmp(A_name.c_str(), rhs.c_str()) > 0);
}

bool Pokemon::operator>(const Pokemon& rhs)
{
  return(strcasecmp(A_name.c_str(), rhs.getAName().c_str()) > 0);
}

bool Pokemon::operator==(const std::string& rhs)
{
  return(strcasecmp(A_name.c_str(), rhs.c_str()) == 0);
}

bool Pokemon::operator==(const Pokemon& rhs)
{
  return(strcasecmp(A_name.c_str(), rhs.getAName().c_str()) == 0);
}

std::string Pokemon::getAName() const
{
  return(A_name);
}

Pokemon::~Pokemon()
{}

std::string Pokemon::getDex() const
{
    return(dex);
}
std::string Pokemon::getJName() const
{
    return(J_name);
}
