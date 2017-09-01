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

#include <stdexcept>
#include <string>
#include <iostream>
#include "mazeException.h"

//Exception class
mazeException::mazeException(const char* message): std::runtime_error("")
{
//prints thrown message
  std::cout << "" << std::endl;
  std::cout << message << std::endl;
  std::cout << "" << std::endl;
}
