/*
MedicalExecutive.cpp
Liam Ormiston
9-17-16
File for the MedicalExecutive class
*/

#include "MedicalExecutive.h"
#include "City.h"
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

MedicalExecutive::MedicalExecutive (char fileName [128])
{
  std::ifstream Xfile;
  Xfile.open(fileName);

  if(Xfile.is_open())
  {
    //Once file is open, it will read until a comma or a return
    //It will then assign each string to a variable and then use
    //The city setter to assign those values to a city object.
    std::cout << "Success" << std::endl;

    while (Xfile.good())
    {
      std::string xName;
      std::string xPop;
      std::string xLevel;

      std::getline(Xfile, xName, ',');
      std::getline(Xfile, xPop, ',');
      std::getline(Xfile, xLevel, '\n');

      if(xName != "")
      {
        //LinkedList<City> cityList;
        City temp_city(xName, std::stoi(xPop), std::stoi(xLevel));
        /*if (!cityList.isEmpty())
        {
          std::cout << "Yay" <<std::endl;
        }*/
        //cityList.addSorted(temp_city);
        std::cout << temp_city.getName() << " " << temp_city.getPop()<< " " << temp_city.getLevel() << std::endl;
      }
    }
  }
  else
  {
    std::cout << "Error" <<std::endl;
  }
  Xfile.close();
}

/*void MedicalExecutive::addSorted(City n_City)
{
  LinkedList<City>* cityList = nullptr;

  {
    if(cityList->isEmpty())
    {
      cityList->addFront(n_City);
      m_length++;
    }
    else
    {
      int temp_pos = 1;
      for(int i=1; i<= m_length; i++)
      {
        if(n_City.getPop() > cityList->getEntry(i).getPop())
        {
          temp_pos++;
        }
        if (cityList->getEntry(i) == nullptr)
        {
          cityList->addBack(n_City);
          cityList->setEntry(temp_pos, n_City);
          m_length ++;
        }
        else
        {
          cityList->insert(i, n_City);
        }
      }
    }
  }
}*/

void MedicalExecutive::run()
{
  int choice =0;
std::cout << "Make a selection:"<< std::endl;
std::cout << "1) Increase infection level of all cities" << std::endl;
std::cout << "2) Increase infection level of specific city" << std::endl;
std::cout << "3) Print status of a specific city" << std::endl;
std::cout << "4) Create quarantine log" << std::endl;
std::cout << "5) Print all cities above an infection level" << std::endl;
std::cout << "6) Exit" << std::endl;

std::cin >> choice;

while(choice > 6 || choice == 0)
{
  std::cout <<"that is not an option please try again" << std::endl;
  std::cin >> choice;
}


}
