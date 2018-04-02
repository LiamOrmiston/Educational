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
#include <math.h>

class MinMaxHeap {
public:
  MinMaxHeap();
  ~MinMaxHeap();
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
	int minmax_arr[500]{-1};
  int last_index;
  std::ifstream file;
};
#endif
