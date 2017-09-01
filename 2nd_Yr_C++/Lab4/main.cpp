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
#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>

//Runs the program as long as the user passes a file to open after
//calling the program to run. If the user doesn't pass a file to read then
//the user will be prompted again.
int main(int argc, char** argv)
{
    if(argc>=2)
    {
        Executive exec(argv[1]);
        exec.run();
    }
    else
    {
        std::cout << "too many or few args!" << std::endl;
    }
    return 0;
}
