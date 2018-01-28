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
#include <stdexcept>
#include <string>
#include <iostream>
#include "PreconditionViolationException.h"

//Declares exception class for Precondition
PreconditionViolationException::PreconditionViolationException(const std::string& message): std::runtime_error("Precondition Violation: " + message)
{

}
