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
  int value;
	int min_arr[500];
  int last_index;
  std::ifstream file;
};
#endif
