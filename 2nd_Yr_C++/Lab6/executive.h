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

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include "mazeReader.h"
class executive
{
public:
//constructor
  executive(std::string fileName);

//variables
private:
  std::string fileName;
  std::ifstream file;
  const char* const* mazePointer;
  int m_rows;
  int m_cols;
  int m_startR;
  int m_startC;
};
#endif
