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

#include "Executive.h"
#include <string>
#include <iostream>
#include <fstream>

//constructor
Executive::Executive()
{
}

//run method
void Executive::run()
{
  while (choice != 4)
  {
    std::cout << "-------------------------" << std::endl;
    std::cout << "Please choose an option:" << std::endl;
    std::cout << "1. List Reversal" << std::endl;
    std::cout << "2. Compute C(n)" << std::endl;
    std::cout << "3. Quadtree" << std::endl;
    std::cout << "4. Quit Program" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "" <<std::endl;
    std::cin >> user;
//checks to see if the user gives proper input
    try
    {
      choice = std::stoi(user);
    }
//if the user tries to input anything that isn't an int then program catches and handles the error
    catch (std::invalid_argument)
    {
      std::cout << "Please enter an int" << std::endl;
      std::cout << "" << std::endl;
    }
//initiates the different methods for what the user chooses
    if (choice < 5 && choice > 0)
    {
      if (choice == 1)
      {
        rList();
      }
      else if (choice == 2)
      {
        cN();
      }
      else if (choice == 3)
      {
        int QuadTree[64][64];
        qTree(QuadTree);
      }
      else
      {
        std::cout << "Exiting the program. Thanks!" << std::endl;
      }
    }
//if the user selects an int that isn't 1-4
    else
    {
      std::cout << "Your selection is outside the given range" << std::endl;
    }
  }
//destructor
  list.~LinkedList();
}

//reverse list method
void Executive::rList()
{
//file of strings that the user wants reversed
  std::cout << "Please give the file that you would like to use" << std::endl;
  std::cin >> fileName;
  file.open(fileName);
//reads in each string and adds to a linked list of strings
  while (file.good())
  {
    file >> temp;
    list.addBack(temp);
  }
    file.close();
//prints list
    for (int i = 1; i < list.getLength(); i ++)
    {
      temp = list.getEntry(i);
      std::cout << temp <<std::endl;
    }

    std::cout << "" << std::endl;

//reverses list
    list.reverseList();
//prints list in reverse
    for (int i = 2; i <= list.getLength(); i ++)
    {
      temp = list.getEntry(i);
      std::cout << temp <<std::endl;
    }
}

//c(n) initiator method
void Executive::cN()
{
  int x = 0;
  std::cout << "Would you like to count permuatations? (Y/y , N/n)" << std::endl;
  std::cin >> user;
  if (user == "y"|| user == "Y")
  {
    std::cout << "Enter a value to compute" << std::endl;
    std::cin >> x;
    C_Perm = cPerm(x);
    C = c(x);
    std::cout << "Permuatations: " << C_Perm << std::endl;
    std::cout << "Result: " << C-1 << std::endl;

  }
  else if (user == "n"|| user == "N")
  {
    std::cout << "Enter a value to compute" << std::endl;
    std::cin >> x;
    C = c(x);
    std::cout << "Result: " << C-1 << std::endl;
  }
  //if user doesn't use the proper syntax then they will be prompted to try again
  else
  {
    std::cout << "Invalid input. Try again" << std::endl;
    cN();
  }
}

//c(n) calculator initiator method
int Executive::c(int x)
{
  return Compute((x+1), (x+1));
}

//c(n) permuatations method
int Executive::cPerm (int x)
{
  int total = 0;
  if (x == 0)
  {
    return (0);
  }
  else
  {
    for (int i = (x-1); i > 0; i--)
    {
      total = ((cPerm(x-1)*2)+1);
    }
  }
  return total;
}

//c(n) calculator method
int Executive::Compute(int num, int highestRemaining)
{
  int total = 0;
  if (highestRemaining == 0 || highestRemaining == 1)
  {
    return(1);
  }

  for(int i = highestRemaining; i > 0; i--)
  {
    if(i<=num)
    {
      total += Compute((num-i), i);
    }
  }
  return(total);
}

//quadtree initiator method
void Executive::qTree(int q[64][64])
{
  std::cout << "Please give the file that you would like to use" << std::endl;
  std::cin >> fileName;
  file.open(fileName);
  int num;
  for(int i = 0; i < 64; i++)
  {
    for(int j = 0; j < 64; j++)
    {
      file >> num;
      q[i][j] = num;
    }
  }
  file.close();
  SimpleCells(q, 0, 63, 0, 63);
}

//quadtree calculator method
void Executive::SimpleCells(int q[64][64], int firstRow, int lastRow, int firstColumn, int lastColumn)
{
  int num = 0;
  int numOnes = 0;
  int midRow = (firstRow+lastRow)/2;
  int midCol = (firstColumn+lastColumn)/2;

  for(int i = firstRow; i <= lastRow; i++)
  {
    for (int j = firstColumn; j <= lastColumn; j++)
    {
      num = q[i][j];
      if (num == 1)
      {
        numOnes++;
      }
      if (numOnes > 1)
        {
          SimpleCells(q, firstRow, midRow, firstColumn, midCol); //NW
          SimpleCells(q, firstRow, midRow, midCol+1, lastColumn); //NE
          SimpleCells(q, midRow+1, lastRow, midCol+1, lastColumn); //SE
          SimpleCells(q, midRow+1, lastRow, firstColumn, midCol); //SW
          return;
        }
      }
    }
    if (numOnes == 1)
    {
      std::cout << "Row: " << firstRow << " through " << lastRow << std::endl;
      std::cout << "Column: " << firstColumn << " through " << lastColumn << std::endl;
      std::cout << "ONE" << std::endl;
    }
    else
    {
      std::cout << "Row: " << firstRow << " through " << lastRow << std::endl;
      std::cout << "Column: " << firstColumn << " through " << lastColumn << std::endl;
      std::cout << "EMPTY" << std::endl;
    }
  }
