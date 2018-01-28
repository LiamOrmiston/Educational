/*
---------------------------
Author: Liam Ormiston
Date late updated: 10-13-16
Project: Lab 05 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Recursive exercises
---------------------------
*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
  private:
    T m_value;
    Node<T>* m_previous;
    Node<T>* m_next;

//defines methods used in the hpp file
  public:
    Node();
    void setValue(T val);
    T getValue() const;
    void setNext(Node<T>* next);
    Node<T>* getNext() const;
    void setPrev(Node<T>* prev);
    Node<T>* getPrev() const;
};

#include "Node.hpp"
#endif
