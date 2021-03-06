/*
 * Node.h
 * Liam Ormiston
 * 3-12-18
 * Header file for the Node class
 */
#ifndef NODE_H
#define NODE_H

#include<string>
#include<iostream>

template <typename T>
class Node {
public:
  Node();
  ~Node();
  T getValue();
  Node<T>* getNext();
  void setValue(T value);
  void setNext(Node<T>* next);
private:
  T m_value;
  Node<T>* m_next;
};
#include "Node.hpp"
#endif
