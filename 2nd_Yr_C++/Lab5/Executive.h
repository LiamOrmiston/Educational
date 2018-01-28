/*
---------------------------
Author: Liam Ormiston
Date late updated: 10-13-16
Project: Lab 05 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Recursive exercises
---------------------------
*/

#ifndef EXECUTIVE_H
#define  EXECUTIVE_H
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

class Executive
{
public:
  Executive();
  void run();
  void rList();
  void cN();
  int c(int x);
  int cPerm (int x);
  int Compute(int num, int highestRemaining);
  void qTree(int q[64][64]);
  void SimpleCells(int q[64][64], int firstRow, int lastRow, int firstColumn, int lastColumn);

private:
  std::ifstream file;
  int choice;

  std::string fileName;
  std::string user;
  std::string temp;
  LinkedList<std::string> list;

  int C;
  int C_Perm;
};

#endif
