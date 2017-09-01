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

#include <iostream>
#include <string>
#include <fstream>
#include "executive.h"
#include "mazeReader.h"
#include "MazeWalker.h"

executive::executive(std::string fileName)
{
//if an incorrect file was given then the program will ask for another file
  file.open(fileName);
    while(!file.is_open())
    {
      std::cout << "" << std::endl;
      std::cout << "Incorrect file name! Please enter another file:" << std::endl;
      std::cin >> fileName;
      file.open(fileName);
    }

//reads maze file
    mazeReader read(fileName);
    m_rows = read.getRows();
    m_cols = read.getCols();
    m_startR = read.getStartRow();
    m_startC = read.getStartCol();
    mazePointer = read.getMaze();

//walks the maze
    mazeWalker walk(mazePointer, m_startR, m_startC, m_rows, m_cols);
}
