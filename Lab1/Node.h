/*
Node.h
Liam Ormiston
1-29-18
Header file for the Node class
*/
#ifndef NODE_H
#define NODE_H

#include<string>
#include<iostream>

template <typename T>
class Node {
public:
  Node();
  T getValue();
  Node<T>* getNext();
  void setValue(T value);
  void setNext(Node<T> next);
private:
  T m_value;
  Node<T>* m_next;
};
#endif
