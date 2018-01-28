/*
LinkedList.h
Liam Ormiston
1-29-18
Header file for LinkedList class
*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

template <typename T>
class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  bool isEmpty() const;
  bool insert(T value);
  bool erase(T value);
  void print();
  bool find(T value);
private:
  Node<T>* m_front;
  int m_length;
};
#endif
