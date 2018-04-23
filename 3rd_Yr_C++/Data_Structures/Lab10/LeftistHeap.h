/*
 * LeftistHeap.h
 * Liam Ormiston
 * 4-24-18
 * Leftist heap class header
 */
#ifndef LEFTIST_HEAP
#define LEFTIST_HEAP
#include <fstream>
#include <iostream>
#include "LeftistNode.h"

template <typename T>
class LeftistHeap {
public:
  LeftistHeap();
  ~LeftistHeap();
  void buildHeap();
  LeftistNode<T>* concate(LeftistNode<T>*H1, LeftistNode<T>*H2);
  void insert(const int value);
  void deleteMin();
  void setRank(LeftistNode<T>* subTreePtr);
  int getRank(LeftistNode<T>* subTreePtr);
  // Traversals
 void pre();
 void preHelper(LeftistNode<T>* subTreePtr);
 void in();
 void inHelper(LeftistNode<T>* subTreePtr);
 void level();
private:
  LeftistNode<T>* rootPtr = nullptr;
  std::ifstream file;
  void destroyTree(LeftistNode<T>* subTreePtr);
};
#include "LeftistHeap.hpp"
#endif
