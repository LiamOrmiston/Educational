#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>

class City
{
public:
  City(std::string Name, int Pop, int Level);
  void setName(std::string Name);
  void setPop(int Pop);
  void setLevel(int Level);
  std::string getName();
  int getPop();
  int getLevel();

private:
  std::string c_Name;
  int c_Pop;
  int c_Level;
};
//#include "City.cpp"
#endif
