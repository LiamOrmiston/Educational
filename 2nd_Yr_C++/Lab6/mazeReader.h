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

#ifndef MAZEREADER_H
#define MAZEREADER_H
#include <iostream>
#include <fstream>
#include "mazeException.h"

class mazeReader
{
  public:
  /**
  *	@post A mazeReader is created. A 2D char array is allocated with the maze information.
  *	@throws MazeCreationExecption
  *
  */
  mazeReader(std::string fileName) throw (mazeException);

  /**
  *	@post The maze is deallocated.
  */

  ~mazeReader();

  /**
  *	@pre the file was formatting and read in correctly
  *	@return Returns pointer to the maze
  */
  const char* const* getMaze() const;

  /**
  *	@pre the file was formatted and read in correctly
  *	@returns the number of columns listed in the file
  */
  int getCols() const;

  /**
  *	@pre the file was formatted and read in correctly
  *	@returns the number of rows listed in the file
  */
  int getRows() const;

  /**
  *	@pre the file was formatted and read in correctly
  *	@returns the starting column
  */
  int getStartCol() const;

  /**
  *	@pre the file was formatted and read in correctly
  *	@returns the starting row
  */
  int getStartRow() const;



  private:
  /**
  *	@pre the file is properly formatted
  *	@post the characters representing the maze are stores
  */
  void readMaze()	throw (mazeException);

  std::ifstream file;
  int row;
  int col;
  int startRow;
  int startCol;
  char check;
  bool hasExit = false;
  char** mazeArray;

};

#endif
