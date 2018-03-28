/*
 * MaxHeap.h
 * Liam Ormiston
 * 3-27-18
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
  int value;
	int max_arr[500]{-1};
  int last_index;
  std::ifstream file;
};
#endif
