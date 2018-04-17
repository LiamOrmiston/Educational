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
#include <math.h>

class LeftistHeap {
public:
  LeftistHeap();
  ~LeftistHeap();
  void buildHeap();
  void concate(H1, H2);
  void insert(const int value);
  void deleteMin();
  void findMin();
  void levelOrder();
private:
  LeftistNode<T>* rootPtr;
  void destroyTree(BinaryNode<T>* subTreePtr);
  std::ifstream file;
};
#endif
