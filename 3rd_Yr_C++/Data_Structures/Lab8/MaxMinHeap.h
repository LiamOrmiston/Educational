/*
 * MaxMinHeap.h
 * Liam Ormiston
 * 4-2-18
 * Max-min heap class header
 */
#ifndef MAX_MIN_HEAP
#define MAX_MIN_HEAP
#include <fstream>
#include <iostream>
#include <math.h>

class MaxMinHeap {
public:
  MaxMinHeap();
  ~MaxMinHeap();
  void buildHeap();
  bool has_gchild(int index);
  void swap(int index);
  void swap_child(int index);
  void swap_gchild(int index);
  bool isMinLevel(int index);
  void patch(int index);
  void patch_with_child(int index);
  void patch_with_gchild(int index);
  void insert(const int value);
  void deleteMin();
  void deleteMax();
  void findMin();
  void findMax();
  void levelOrder();
private:
	int maxmin_arr[500]{-1};
  int last_index;
  std::ifstream file;
};
#endif
