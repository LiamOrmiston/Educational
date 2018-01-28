#ifndef POKEMON_H
#define POKEMON_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <strings.h>
#include <stdio.h>

class Pokemon
{
  public:
    Pokemon(std::string name_A, std::string num, std::string name_J);
    bool operator<(const std::string& rhs);
    bool operator<(const Pokemon& rhs);
    bool operator>(const std::string& rhs);
    bool operator>(const Pokemon& rhs);
    bool operator==(const std::string& rhs);
    bool operator==(const Pokemon& rhs);
    std::string getAName() const;
    std::string getDex()const;
    std::string getJName() const;
    ~Pokemon();

  private:
    std::string A_name;
    std::string dex;
    std::string J_name;

};
#endif
