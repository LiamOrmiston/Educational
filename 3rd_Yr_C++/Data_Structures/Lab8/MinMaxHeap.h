/*
 * MinMaxHeap.h
 * Liam Ormiston
 * 4-2-18
 * Minmax heap class header
 */
#ifndef MIN_MAX_HEAP
#define MIN_MAX_HEAP
#include <fstream>
#include <iostream>

class MinMaxHeap {
public:
  MinMaxHeap();
  ~MinMaxHeap();
  void buildHeap();
  void insert(const int value);
  void deleteMin();
  void deleteMax();
  void findMin();
  void findMax();
  void levelOrder();
private:
	int minmax_arr[500]{-1};
  int last_index;
  std::ifstream file;
};
#endif
