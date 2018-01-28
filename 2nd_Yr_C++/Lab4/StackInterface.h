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

// StackInterface.h - An interface for various stack methods
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include "PreconditionViolationException.h"


template <typename T>
class StackInterface
{
public:
virtual ~StackInterface() {};
virtual bool isEmpty() const = 0;
    //returns true if the stack is empty, false otherwise
virtual void push(const T value) throw(PreconditionViolationException) = 0;
    //Entry added to top of stack
    //thrown PreconditionViolationException if push cannot occur (e.g. stack full)
virtual void pop() throw(PreconditionViolationException) = 0;
    //assumes the stack is not empty
    //top of the stack is removed
    //throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
virtual T peek() const throw(PreconditionViolationException) = 0;
    //assumes the stack is not empty
    //returns the value at the top of the stack
    //throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case.
};

#endif
