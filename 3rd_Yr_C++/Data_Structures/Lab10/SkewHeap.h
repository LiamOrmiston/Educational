/*
 * SkewHeap.h
 * Liam Ormiston
 * 4-24-18
 * Skew heap header
 */
#ifndef SKEW_HEAP
#define SKEW_HEAP
#include <fstream>
#include <iostream>
#include "SkewNode.h"

template <typename T>
class SkewHeap {
public:
  SkewHeap();
  ~SkewHeap();
  void buildHeap();
  SkewNode<T>* concate(SkewNode<T>*H1, SkewNode<T>*H2);
  void insert(const int value);
  void deleteMin();
  // Traversals
 void pre();
 void preHelper(SkewNode<T>* subTreePtr);
 void in();
 void inHelper(SkewNode<T>* subTreePtr);
 void level();
private:
  SkewNode<T>* rootPtr = nullptr;
  std::ifstream file;
  void destroyTree(SkewNode<T>* subTreePtr);
};
#include "SkewHeap.hpp"
#endif
