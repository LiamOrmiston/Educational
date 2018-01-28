/*
---------------------------
Author: Liam Ormiston
Date late updated: 9-6-16
Project: Lab 01 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Voter Registration
---------------------------
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <iostream>

class VPR;
class Executive
{
  //Declares all variables used in executive.cpp
    private:
        int n_records;
        VPR* records;
        bool exist;
    public:
        //constructor
        Executive(char fileName[128]);
        //deconstructor
        ~Executive();
        //runs the main code in executive.cpp
        void run();
};


#endif // EXECUTIVE_H
