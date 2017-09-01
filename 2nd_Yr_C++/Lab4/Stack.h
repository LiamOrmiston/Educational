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

#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"


template <typename T>
class Stack : public StackInterface<T>
{
  private:
    Node<T>* m_top;
    int m_size;

//defines method used in hpp
  public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    void push(const T newEntry) throw (PreconditionViolationException);
    void pop() throw(PreconditionViolationException);
    T peek() const throw(PreconditionViolationException);
};

#include "Stack.hpp"
#endif
