/*
 * MinMaxHeap.cpp
 * Liam Ormiston
 * 4-2-18
 * Min heap class
 */
#include "MinMaxHeap.h"

  MinMaxHeap::MinMaxHeap(){
    // initalize MinMaxHeap with values from data.txt
    file.open("data.txt");
    int value = 0;
    int i = 1;
    while (file >> value) {
      minmax_arr[i] = value;
      last_index = i;
      i++;
    }
    buildHeap();
  }
  MinMaxHeap::~MinMaxHeap(){
    // delete minmax_arr;
  }
  void MinMaxHeap::buildHeap(){
    int last_parent = floor(last_index/2);
    for (int i = last_parent; i > 0; i--) {
      swap(i);
      }
    }
  }
  bool MinMaxHeap::has_gchild(int index) {
    if(index*4 <= last_index) {
      return true;
    }
    else {
      return false;
    }
  }
  void MinMaxHeap::swap(int index) {
    if(has_gchild(index)) {
      swap_gchild(index);
    }
    else {
      swap_child(index);
    }
  }
  void MinMaxHeap::swap_child(int index) {
    if(isMinLevel(index)) {
      int min = index;
      int child1 = index*2;
      int child2 = index*2+1;
      if (minmax_arr[min] > minmax_arr[child1]) {
        min = child1;
      }
      if (minmax_arr[min] > minmax_arr[child2] && child2 <= last_index) {
        min = child2;
      }
      if (index != min) {
        int temp = minmax_arr[index];
        minmax_arr[index] = minmax_arr[min];
        minmax_arr[min] = temp;
      }
    }
    else {
      int max = index;
      int child1 = index*2;
      int child2 = index*2+1;
      if (minmax_arr[max] < minmax_arr[child1]) {
        max = child1;
      }
      if (minmax_arr[max] < minmax_arr[child2] && child2 <= last_index) {
        max = child2;
      }
      if (index != max) {
        int temp = minmax_arr[index];
        minmax_arr[index] = minmax_arr[max];
        minmax_arr[max] = temp;
      }
    }
  }
  void MinMaxHeap::swap_gchild(int index) {
    if(isMinLevel(index)) {
      int min = index;
      int g_child1 = index*4;
      int g_child2 = index*4+1;
      int g_child3 = index*4+2;
      int g_child4 = index*4+3;

      if (minmax_arr[min] > minmax_arr[g_child1]) {
        min = g_child1;
      }
      if (minmax_arr[min] > minmax_arr[g_child2] && g_child2 <= last_index) {
        min = g_child2;
      }
      if (minmax_arr[min] > minmax_arr[g_child3] && g_child3 <= last_index) {
        min = g_child3;
      }
      if (minmax_arr[min] > minmax_arr[g_child4] && g_child4 <= last_index) {
        min = g_child4;
      }
      if (index != min) {
        int temp = minmax_arr[index];
        minmax_arr[index] = minmax_arr[min];
        minmax_arr[min] = temp;
      }
    }
    else {
      int max = index;
      int g_child1 = index*4;
      int g_child2 = index*4+1;
      int g_child3 = index*4+2;
      int g_child4 = index*4+3;

      if (minmax_arr[max] < minmax_arr[g_child1]) {
        max = g_child1;
      }
      if (minmax_arr[max] < minmax_arr[g_child2] && g_child2 <= last_index) {
        max = g_child2;
      }
      if (minmax_arr[max] < minmax_arr[g_child3] && g_child3 <= last_index) {
        max = g_child3;
      }
      if (minmax_arr[max] < minmax_arr[g_child4] && g_child4 <= last_index) {
        max = g_child4;
      }
      if (index != max) {
        int temp = minmax_arr[index];
        minmax_arr[index] = minmax_arr[max];
        minmax_arr[max] = temp;
      }
    }
  }
  bool MinMaxHeap::isMinLevel(int index) {
    int num = floor(log2(index));
    if(fmod(num, 2) == 0) {
      return true;
    }
    else {
      return false;
    }
  }
  void MinMaxHeap::insert(const int value){
    if (last_index<500) {
      last_index++;
      minmax_arr[last_index] = value;
      buildHeap();
      levelOrder();
    }
    else {
      std::cout << "Minmax heap is full. Cannot insert " << value << std::endl;
    }
  }
  void MinMaxHeap::deleteMin(){
    if (last_index>=1) {
      int parent = 0;
      minmax_arr[parent] = -1;
      int smallest_child = 0;
      bool at_leaf = false;
      // traverses all the children of a set parent to find smallest child
      while (!at_leaf) {
        smallest_child = 5*parent+1;
        if (smallest_child > last_index) {
          // shift all the values where the smallest value got deleted
          minmax_arr[parent] = minmax_arr[last_index];
          last_index--;
          at_leaf = true;
        }
        else {
          // find smallest child
          for (int i = 1; i <= 5 && 5*parent+i <= last_index; i++) {
            if(minmax_arr[smallest_child] > minmax_arr[5*parent+i]) {
              smallest_child = 5*parent+i;
            }
          }
          // replace parent with smallest child
          minmax_arr[parent] = minmax_arr[smallest_child];
          parent = smallest_child;
          minmax_arr[parent] = -1;
        }
      }
      levelOrder();
    }
    else {
      std::cout << "Minmax heap is empty." << std::endl;
    }
  }
  void MinMaxHeap::deleteMax(){
    if (last_index >= 1) {
      int max_index = floor((last_index-1)/5) + 1;
      for (int i = max_index+1; i < last_index; i++) {
        if (minmax_arr[max_index] < minmax_arr[i]) {
          max_index = i;
        }
      }
      minmax_arr[max_index] = minmax_arr[last_index];
      last_index--;
      levelOrder();
    }
    else {
      std::cout << "Minmax heap is empty\n";
    }
  }
  void MinMaxHeap::findMin(){
    if (last_index >= 1) {
      std::cout << "Min value: " << minmax_arr[1] << std::endl;
    }
    else {
      std::cout << "Minmax heap is empty\n";
    }
  }
  void MinMaxHeap::findMax(){
    if (last_index > 1) {
      int max_index = floor((last_index-1)/5) + 1;
      for (int i = max_index+1; i < last_index; i++) {
        if (minmax_arr[max_index] < minmax_arr[i]) {
          max_index = i;
        }
      }
      std::cout << "Max value: " << minmax_arr[max_index] << std::endl;
    }
    else if(last_index == 1) {
      std::cout << "Max value: " << minmax_arr[1] << std::endl;
    }
    else {
      std::cout << "Minmax heap is empty\n";
    }
  }
  void MinMaxHeap::levelOrder(){
    if(last_index < 1) {
      std::cout << "Minmax heap is empty\n";
    }
    else {
      int j = 1;
      for (int i = 1; i <= last_index; i++) {
        std::cout << minmax_arr[i] << " ";
        int last_child = pow(2, j)-1;
        if (i == last_child) {
          std::cout << "\n";
          j++;
        }
        else if (i%2 == 1 && i!=last_index) {
        std::cout << "- ";
        }
      }
      std::cout << "\n";
    }
  }
