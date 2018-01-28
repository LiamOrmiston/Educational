/*
---------------------------
Author: Liam Ormiston
Date late updated: 9-6-16
Project: Lab 01 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Voter Registration
---------------------------
*/

#include "vpr.h"
#include <iostream>
#include <fstream>
#include <string>

VPR::VPR()
{
v_firstName = "";
v_lastName = "";
v_aff = "";
v_age = 0;
}

//Creating all set Methods
//reads in value from txt file and assigns the block of text to a
//string or int
void VPR::setfirstName (std::string firstName)
{
    v_firstName = firstName;
}

void VPR::setlastName (std::string lastName)
{
    v_lastName = lastName;
}

void VPR::setaff (std::string aff)
{
    v_aff = aff;
}

void VPR::setage (int age)
{
    v_age = age;
}

//Creating all get Methods
//These methods that will retrieve the info from the text when called on
//most will scan the text to find matches and then display them for the
//user, others will scan to find other things like text within a parameter
//or how many times a function is called.
void VPR::getfirstName (std::string firstName)
{
    std::cout << v_lastName << std::endl;
}

void VPR::getlastName (std::string temp)
{
  if (temp.compare(v_lastName)==0)
  {
    std::cout << v_firstName << " " << v_lastName << " " << v_age << " " << v_aff << std::endl;
  }
}

void VPR::getaff (std::string temp)
{
  if (temp.compare(v_aff)==0)
  {
    std::cout << v_firstName << " " << v_lastName << " " << v_age << " " << v_aff << std::endl;
  }
}

int VPR::getaffCount (std::string temp)
{
int count = 0;
  if (temp.compare(v_aff)==0)
  {
    count++;
  }
  return (count);
}

void VPR::getage (int low, int high)
{
    if (v_age>=low && v_age<=high)
    {
      std::cout << v_firstName << " " << v_lastName << " " << v_age << " " << v_aff << std::endl;
    }
}
