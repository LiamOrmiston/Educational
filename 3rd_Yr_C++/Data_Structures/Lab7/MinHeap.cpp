#include "MinHeap.h"
#include <math.h>

  MinHeap::MinHeap(){
    // initalize MinHeap with values from data.txt
    file.open("data.txt");
    int value = 0;
    int i = 0;
    while (file >> value) {
      min_arr[i] = value;
      last_index = i;
      i++;
    }
    levelOrder();
    buildHeap();
  }
  MinHeap::~MinHeap(){
    // delete min_arr;
  }
  void MinHeap::buildHeap(){
    for (int i = last_index; i > 0; i--) {
      int parent = floor((i-1)/5);
      int child = i;
      // is the child is smaller than it's parent?
      while (min_arr[child] < min_arr[parent]) {
        std::cout << "swapping " << min_arr[child] << " with " << min_arr[parent] << '\n';
        // swap parent with child
        int temp = min_arr[child];
        min_arr[child] = min_arr[parent];
        min_arr[parent] = temp;
        child = parent;
        parent = floor((parent-1)/5);
      }
    }
    // std::cout << "buildHeap() still needs to be implemented\n";
  }
  void MinHeap::insert(const int value){
    if (last_index<500) {
      last_index++;
      min_arr[last_index] = value;
      buildHeap();
      levelOrder();
    }
    else {
      std::cout << "Min heap is full. Cannot insert " << value << std::endl;
    }
  }
  void MinHeap::deleteMin(){
    if (last_index>0) {
      int parent = 0;
      min_arr[parent] = -1;
      // traverses all the children of a set parent to find smallest child
      while (min_arr[parent] == -1) {
        int smallest_child = min_arr[5*parent+1];
        for (int i = 1; i <= 5; i++) {
          if(min_arr[smallest_child] > min_arr[5*parent+i]) {
            smallest_child = 5*parent+i;
          }
        }
        // if smallest child is a leaf then replace parent and replace child with
        // the next index until the last index. (shift everything over)

        // replace
        std::cout << min_arr[smallest_child] << " is the smallest child. Swapping..." << '\n';
        min_arr[parent] = min_arr[smallest_child];

        // first child is a leaf
        if (min_arr[5*parent+1] == -1) {
          std::cout << "parent is a leaf" << '\n';
          // shift all the values where the smallest value got deleted
          for (int i = smallest_child; i < last_index; i++) {
            min_arr[smallest_child] = min_arr[smallest_child+1];
          }
          last_index--;
        }
        else {
          std::cout << "parent is not a leaf" << '\n';
          parent = smallest_child;
          std::cout << "next parent index is " << parent << '\n';
          min_arr[parent] = -1;
        }
      }
      levelOrder();
    }
    else {
      std::cout << "Min heap is empty." << std::endl;
    }
  }
  void MinHeap::deleteMax(){
    if (last_index > 0) {
      int max_index = floor((last_index-1)/5) + 1;
      for (int i = max_index+1; i < last_index; i++) {
        if (min_arr[max_index] < min_arr[i]) {
          max_index = i;
        }
      }
      for (int i = max_index; i < last_index; i++) {
        min_arr[i] = min_arr[i+1];
      }
      last_index--;
      buildHeap();
      levelOrder();
    }
    else {
      std::cout << "Min heap is empty\n";
    }
  }
  void MinHeap::findMin(){
    if (last_index > 0) {
      std::cout << "Min value: " << min_arr[0] << std::endl;
    }
    else {
      std::cout << "Min heap is empty\n";
    }
  }
  void MinHeap::findMax(){
    if (last_index > 0) {
      int max_index = floor((last_index-1)/5) + 1;
      for (int i = max_index+1; i < last_index; i++) {
        if (min_arr[max_index] < min_arr[i]) {
          max_index = i;
        }
      }
      std::cout << "Max value: " << min_arr[max_index] << std::endl;
    }
    else {
      std::cout << "Min heap is empty\n";
    }
  }
  void MinHeap::levelOrder(){
    for (int i = 0; i <= last_index; i++) {
      std::cout << min_arr[i] << " ";
      if (i==0 || i==5 || i==30 || i==155) {
      std::cout << "\n";
      }
      else if (i%5 == 0 && i!=last_index) {
      std::cout << "- ";
      }
    }
    std::cout << "\n";
  }
