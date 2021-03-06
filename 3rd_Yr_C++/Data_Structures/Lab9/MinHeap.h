/*
 * MinHeap.h
 * Liam Ormiston
 * 4-12-18
 * Min heap class header
 */
#ifndef MIN_HEAP
#define MIN_HEAP
#include <fstream>
#include <iostream>

class MinHeap {
public:
  MinHeap();
  ~MinHeap();
  void buildHeap();
  void insert(const int value);
  void deleteMin();
  void deleteMax();
  void findMin();
  void findMax();
  void levelOrder();
private:
	int min_arr[10000000]{-1};
  int last_index =0;
  std::ifstream file;
};
#endif
