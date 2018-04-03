/*
 * MaxHeap.h
 * Liam Ormiston
 * 4-12-18
 * Max heap class header
 */
#ifndef MAX_HEAP
#define MAX_HEAP
#include <fstream>
#include <iostream>

class MaxHeap {
public:
  MaxHeap();
  ~MaxHeap();
  void buildHeap();
  void insert(const int value);
  void deleteMin();
  void deleteMax();
  void findMin();
  void findMax();
  void levelOrder();
private:
	int max_arr[10000000]{-1};
  int last_index;
  std::ifstream file;
};
#endif
