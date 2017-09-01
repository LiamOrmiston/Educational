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

// QueueInterface.h - An interface for various queue methods
#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

#include "PreconditionViolationException.h"

template <typename T>
class QueueInterface
{
public:
  //virtual ~QueueInterface() {}
  virtual bool isEmpty() const = 0;
    //returns true if the stack is empty, false otherwise
  virtual void enqueue(const T value) = 0;
    //Entry added to back of queue
  virtual void dequeue() throw(PreconditionViolationException) = 0;
    //assumes the queue is not empty
    //front of the front is removed
    //throws PreconditionViolationException ifattempted on an empty queue. Does not return a value in this case.
  virtual T peekFront() const throw(PreconditionViolationException) = 0;
    //assumes the queue is not empty
    //returns the value at the front of the stack
    //throws a PreconditionViolationException if attempted on an empty queue. Does not return a value in this case.
};

#endif
