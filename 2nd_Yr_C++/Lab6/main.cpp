/*
---------------------------
Author: Liam Ormiston
Date late updated: 10-24-16
Project: Lab 06 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Maze Walker
---------------------------
*/

#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

//expects user to provide a txt file when running the program
int main(int argc, char** argv)
{
  if(argc == 2)
  {
      executive exec(argv[1]);
  }

//if a file isn't given then prompt the user for a file.
  else
  {
    std::cout << "" << std::endl;
    std::cout << "Please give the name of a file" << std::endl;
    std::cout << "" << std::endl;
  }
  return 0;
}
