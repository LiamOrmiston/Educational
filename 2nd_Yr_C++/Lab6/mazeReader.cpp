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
#include <fstream>
#include <string>
#include "mazeReader.h"

//constructor
mazeReader::mazeReader(std::string fileName) throw (mazeException)
{
  //try block throws exception if the starting row and column is out of bounds
  try
  {
    file.open(fileName);

    //gets parameters of the maze
    if(file.is_open())
    {
      file >> row;
      file >> col;
      file >> startRow;
      file >> startCol;
    }

    //delcares the 2D array size after getting the size from the file
    mazeArray = new char* [row];
    for(int i = 0; i < row; ++i)
    {
      mazeArray[i] = new char [col];
    }

    if(file.is_open())
    {
      //checks to make sure the starting row and column is within the size bounds
      if (startRow > row || startCol > col)
      {
        throw mazeException("Invalid starting position");
      }

      //will read in the entries into the array
      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < col; j++)
        {
          file >> check;
          mazeArray[i][j] = check;

          //checks to see if the program has an exit
          if(check == 'E')
          {
            hasExit = true;
          }
        }
      }
    }

    file.close();

    std::cout << "Starting postion: " << startRow << ", " << startCol << std::endl;
    std::cout << "Size: " << row << ", " << col << std::endl;

    //if program doesn't have an exit then throws exception
    if(!hasExit)
    {
      throw mazeException ("No way out!");
    }
  }
  catch (mazeException e){}
}


/**
*	@pre the file was formatting and read in correctly
*	@return Returns pointer to the maze
*/
const char* const* mazeReader::getMaze() const
{
  return mazeArray;
}

/**
*	@pre the file was formatted and read in correctly
*	@returns the number of columns listed in the file
*/
int mazeReader::getCols() const
{
  return col;
}

/**
*	@pre the file was formatted and read in correctly
*	@returns the number of rows listed in the file
*/
int mazeReader::getRows() const
{
  return row;
}

/**
*	@pre the file was formatted and read in correctly
*	@returns the starting column
*/
int mazeReader::getStartCol() const
{
  return startCol;
}

/**
*	@pre the file was formatted and read in correctly
*	@returns the starting row
*/
int mazeReader::getStartRow() const
{
  return startRow;
}

//destructor
mazeReader::~mazeReader()
{
  if(mazeArray != nullptr)
  {
    for(int i = 0; i < row; ++i)
    {
      delete [] mazeArray[i];
    }
    delete [] mazeArray;
  }
}
