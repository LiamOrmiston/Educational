/*
* MaxHeap.cpp
* Liam Ormiston
* 4-12-18
* Max heap class
*/
#include "MaxHeap.h"
#include <math.h>

MaxHeap::MaxHeap(){
}
MaxHeap::~MaxHeap(){
  // delete max_arr;
}
void MaxHeap::buildHeap(){
  int largest_child = last_index;
  int last_parent = floor((last_index-1)/5);
  int current_parent = last_parent;
  int temp_parent = 0;
  for (int i = last_index; i > 0; i--) {
    temp_parent = floor(((i-1)-1)/5);
    if (temp_parent == current_parent && i != 1) {
      if (max_arr[largest_child] < max_arr[i-1]) {
        largest_child = i-1;
      }
    }
    else {
      if (max_arr[current_parent] < max_arr[largest_child]) {
        int temp = max_arr[current_parent];
        max_arr[current_parent] = max_arr[largest_child];
        max_arr[largest_child] = temp;
        bool done = false;
        while (!done && (5*largest_child+1) < last_index) {
          int new_largest = 5*largest_child+1;
          for(int j = new_largest; j < last_index && j <= 5*largest_child+5; j++) {
            if(max_arr[new_largest] < max_arr[j]) {
              new_largest = j;
            }
          }
          // done = true;
          if (max_arr[new_largest] > max_arr[largest_child]) {
            temp = max_arr[largest_child];
            max_arr[largest_child] = max_arr[new_largest];
            max_arr[new_largest] = temp;
          }
          largest_child = new_largest;
        }
      }
      current_parent = temp_parent;
      largest_child = i-1;
    }
  }
}
void MaxHeap::insert(const int value){
  if (last_index<10000000) {
    last_index++;
    max_arr[last_index] = value;
  }
  else {
    std::cout << "Max heap is full. Cannot insert " << value << std::endl;
  }
}
void MaxHeap::deleteMax(){
  if (last_index>=0) {
    int parent = 0;
    max_arr[parent] = -1;
    int largest_child = 0;
    bool at_leaf = false;
    // traverses all the children of a set parent to find largest child
    while (!at_leaf) {
      largest_child = 5*parent+1;
      if (largest_child > last_index) {
        // shift all the values where the largest value got deleted
        max_arr[parent] = max_arr[last_index];
        last_index--;
        at_leaf = true;
      }
      else {
        // find largest child
        for (int i = 1; i <= 5 && 5*parent+i <= last_index; i++) {
          if(max_arr[largest_child] < max_arr[5*parent+i]) {
            largest_child = 5*parent+i;
          }
        }
        // replace parent with largest child
        max_arr[parent] = max_arr[largest_child];
        parent = largest_child;
        max_arr[parent] = -1;
      }
    }
  }
  else {
    std::cout << "Max heap is empty." << std::endl;
  }
}
void MaxHeap::deleteMin(){
  if (last_index >= 0) {
    int min_index = floor((last_index-1)/5) + 1;
    for (int i = min_index+1; i < last_index; i++) {
      if (max_arr[min_index] > max_arr[i]) {
        min_index = i;
      }
    }
    max_arr[min_index] = max_arr[last_index];
    last_index--;
  }
  else {
    std::cout << "Max heap is empty\n";
  }
}
void MaxHeap::findMax(){
  if (last_index >= 0) {
    std::cout << "Max value: " << max_arr[0] << std::endl;
  }
  else {
    std::cout << "Max heap is empty\n";
  }
}
void MaxHeap::findMin(){
  if (last_index > 0) {
    int min_index = floor((last_index-1)/5) + 1;
    for (int i = min_index+1; i < last_index; i++) {
      if (max_arr[min_index] > max_arr[i]) {
        min_index = i;
      }
    }
    std::cout << "Min value: " << max_arr[min_index] << std::endl;
  }
  else if(last_index == 0) {
    std::cout << "Min value: " << max_arr[0] << std::endl;
  }
  else {
    std::cout << "Max heap is empty\n";
  }
}
