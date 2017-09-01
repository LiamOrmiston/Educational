/*
Node.h
Liam Ormiston
9-15-16
Header file for the Node class
*/
#ifndef NODE_H
#define NODE_H

#include<string>
#include<iostream>

template <typename T>
class Node
{
public:
  Node();
  T getValue();
  void setValue(T value);
  Node<T>* getNext();
  void setNext(Node<T>* next);

private:
  T m_value;
  Node<T>* m_next;
};

//#include "Node.hpp"
#endif
