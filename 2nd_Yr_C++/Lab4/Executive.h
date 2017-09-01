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
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <fstream>
#include <iostream>
#include "Queue.h"
#include "Stack.h"


class Executive
{
  public:
//constructor
    Executive(char fileName[128]);
//runs the main code in Executive.cpp
    void run();

  private:
    Queue<std::string> queue;
    Stack<std::string> stack;
    int limit = 7;
    int onElevator;

    std::ifstream file;
    std::string Command;
    std::string Name;
    std::string Wait = "WAIT";
    std::string Inspection = "INSPECTION";
    std::string Pick_Up = "PICK_UP";
    std::string Drop_Off = "DROP_OFF";
};
#endif
