#ifndef MEDICAL_EXECUTIVE_H
#define MEDICAL_EXECUTIVE_H

#include <string>
#include <iostream>
#include "City.h"
#include "LinkedList.h"

class MedicalExecutive
{
private:
  City temp_city(std::string Name, int Pop, int Level);
  //LinkedList<City>* cityList;
  //LinkedList<City>* q_cityList;
  int m_length;
public:
  MedicalExecutive(char fileName[128]);
  //void addSorted(City n_City);
  void run();

};

#endif
