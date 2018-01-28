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

#include "mazeWalker.h"
#include <iostream>

//constructor
mazeWalker::mazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols)
{
  m_startRow = startRow;
  m_startCol = startCol;
  m_rows = rows;
  m_cols = cols;
  m_array = mazePtr;

//creates a new visited array that will be used to give the solution
  m_visited = new int* [m_rows];
  for(int i = 0; i < m_rows; ++i)
  {
    m_visited[i] = new int [m_cols];
  }

//sets the visited array to all zeros.
//to be further edited...
  for (int i = 0; i < m_rows; i++)
  {
    for (int j = 0; j < m_cols; j++)
    {
      m_visited[i][j] = 0;
    }
  }

//if the exit is reached then it prints the visited array
  if(exitFound())
  {
    for (int i = 0; i < m_rows; i++)
    {
      for (int j = 0; j < m_cols; j++)
      {
        std::cout << m_visited[i][j];
      }
      std::cout << "" << std::endl;
    }

  }
  else
  {
    std::cout << "No exit was found" << std::endl;
  }
}

//destructor
mazeWalker::~mazeWalker()
{
  if(m_visited != nullptr)
  {
    for(int i = 0; i < m_rows; ++i)
    {
      delete [] m_visited[i];
    }
    delete [] m_visited;
  }
}

/**
*	@pre The maze is a valid maze.
*	@post The maze is traversed until the end is reached or all moves are exhausted.
*	@return true if an exit was reached, false otherwise
*/

//calls the walkMaze function with the starting coordinates
//will return true if walkMaze found the exit, false otherwise.
bool mazeWalker::exitFound()
{
  return walkMaze(m_startRow, m_startCol);
}

//walks through the maze starting at the starting coordinate
bool mazeWalker::walkMaze(int current_row, int current_col)
{
//checks to make sure it is still in bounds
//false if out of bounds
  if (current_row == m_rows || current_row < 0 || current_col == m_cols || current_col < 0)
  {
    return false;
  }
//checks for wall
//false if it finds a wall
  else if (m_array[current_row][current_col] == 'W')
  {
    return false;
  }
//checks for the exit
//true if the exit is reached
  else if (m_array[current_row][current_col] == 'E')
  {
    m_visited[current_row][current_col] = m_curStep;
    m_curStep++;
    return true;
  }
//checks for passage
//will set the current coordinate to the step number it took to get there.
//will increase step number
  else if (m_array[current_row][current_col] == 'P' && m_visited [current_row][current_col] == 0)
  {
    m_visited[current_row][current_col] = m_curStep;
    m_curStep++;

//recurses the walk method using the coordinate above
    if(walkMaze(current_row-1, current_col)) //up
    {
      return true;
    }
//recurses the walk method using the coordinate to the right
    if(walkMaze(current_row, current_col+1)) //right
    {
      return true;
    }
//recurses the walk method using the coordinate below
    if(walkMaze(current_row+1, current_col)) //down
    {
      return true;
    }
//recurses the walk method using the coordinate to the left
    if(walkMaze(current_row, current_col-1)) //left
    {
      return true;
    }

//if none of the if statements were run then that means the program reached
//a dead end and will set current coordinate to 0, then pop back to the last step.
    m_visited[current_row][current_col] = 0;
    m_curStep--;
    return false;
  }
  else
  {
    return false;
  }
}

/**
*	@return A const pointer to the visited array. (A pointer that cannot change the array)
*/

/**
*	@return number of rows in maze
*/
int mazeWalker::getVisitedRows() const
{
  return m_rows;
}

/**
*	@return number of cols in maze
*/
int mazeWalker::getVisitedCols() const
{
  return m_cols;
}

/**
*	@return A const pointer to the maze. (A pointer that cannot change the array)
*/
const char* const* mazeWalker::getMaze() const
{
  return m_array;
}
