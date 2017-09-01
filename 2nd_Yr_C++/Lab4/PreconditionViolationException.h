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
#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

#include <stdexcept>
#include <string>

//Exception class for Precondition
class PreconditionViolationException: public std::runtime_error
{
public:
  PreconditionViolationException(const std::string& message = "");
};
#endif
