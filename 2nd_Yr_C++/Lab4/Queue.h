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
#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"

template <typename T>
class Queue: public QueueInterface<T>
{
  private:
    Node<T>* m_front;
    Node<T>* m_back;
    int m_length;

//defines method used in hpp
  public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    void enqueue(const T newEntry);
    void dequeue() throw(PreconditionViolationException);
    T peekFront() const throw(PreconditionViolationException);

};
#include "Queue.hpp"
#endif
