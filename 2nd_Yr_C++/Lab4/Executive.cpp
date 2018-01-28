/*
---------------------------
Author: Liam Ormiston
Date late updated: 10-4-16
Project: Lab 04 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Elevator Action
---------------------------
*/
#include <string>
#include <iostream>
#include <fstream>
#include "Executive.h"

//creates a temporary char array (fileName) in order to read the text file
//that is given upon initializing the program.
Executive::Executive(char fileName[128])
{
//opens file and sets the number of people on the elevator equal to 0.
  file.open(fileName);
  onElevator = 0;
}


//run method
void Executive::run()
{
//reads the first word for the command
  file >> Command;

//loop to run while the end of the file hasn't been reached
while (file.good())
{
//if the word is "WAIT"
  if (Command.compare(Wait) == 0)
  {
//adds name to the queue (line for elevator)
    file >> Name;
    queue.enqueue(Name);
    file >> Command;
  }

//if the word is "INSPECTION"
  if (Command.compare(Inspection) == 0)
  {
//checks to see if the elevator has anyone on it
    if (stack.isEmpty())
    {
      std::cout << "Elevator Status:" << std::endl;
      std::cout << "The Elevator is currently empty" << std::endl;
      std::cout << "No one is in the elevator" << std::endl;
      std::cout << "" << std::endl;
      file >> Command;
    }

//Will display the top of the stack and front of the queue.
    else
    {
      std::string last = stack.peek();
      std::cout << "Elevator Status:" << std::endl;
      std::cout << "Elevator is not empty" << std::endl;
      std::cout << last << " is the next off the elevator" << std::endl;
      try
      {
        std::string front = queue.peekFront();
        std::cout << front << " will be the next person to get on the elevator" << std::endl;
        std::cout << "" << std::endl;
      }
      catch (PreconditionViolationException e)
      {
        std::cout << "No one is in line for the elevator" << std::endl;
      }
      file >> Command;
    }
  }

//if the word is "PICK_UP"
  if (Command.compare(Pick_Up) == 0)
  {
//loop to add people to the elevator until the max of 7 people is reached
    while (onElevator < limit)
    {
      stack.push(queue.peekFront());
      onElevator++;
      queue.dequeue();
    }
    file >> Command;
  }

//if the word is "DROP_OFF"
  if (Command.compare(Drop_Off) == 0)
  {
    std::string last ="";
    std::string temp ="";

//reads next string to get the number of people to drop off
    file >> temp;
    int num = std::stoi(temp);

//will pop off the the number of people given to drop off

      for (int i = 0; i < num; i++)
      {
        try
        {
          stack.pop();
        }
        catch (PreconditionViolationException e)
        {
          std::cout << "Elevator is empty" << std::endl;

        }
        onElevator--;
      }
      file >> Command;
  }
}

//closes file
  file.close();
}
