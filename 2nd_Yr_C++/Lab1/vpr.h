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

#ifndef VPR_H
#define VPR_H

#include <string>
#include <iostream>

//Declares all the variables and methods used in the vpr.cpp file.
class VPR
{
private:
    std::string v_firstName;
    std::string v_lastName;
    std::string v_aff;
    int v_age;
public:
    VPR();
    void setfirstName(std::string firstName);
    void setlastName(std::string lastName);
    void setaff(std::string aff);
    void setage(int age);
    void getfirstName(std::string firstName);
    void getlastName(std::string lastName);
    void getaff(std::string aff);
    int getaffCount(std::string aff);
    void getage(int low, int high);
};

#endif // VPR_H
