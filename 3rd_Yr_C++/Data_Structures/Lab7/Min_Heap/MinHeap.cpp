/*
 * MinHeap.cpp
 * Liam Ormiston
 * 3-27-18
 * Min heap class
 */
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
    buildHeap();
  }
  MinHeap::~MinHeap(){
    // delete min_arr;
  }
  void MinHeap::buildHeap(){
    int smallest_child = last_index;
    int last_parent = floor((last_index-1)/5);
    int current_parent = last_parent;
    int temp_parent = 0;
    for (int i = last_index; i > 0; i--) {
      temp_parent = floor(((i-1)-1)/5);
      if (temp_parent == current_parent && i != 1) {
        if (min_arr[smallest_child] > min_arr[i-1]) {
          smallest_child = i-1;
        }
      }
      else {
        if (min_arr[current_parent] > min_arr[smallest_child]) {
          int temp = min_arr[current_parent];
          min_arr[current_parent] = min_arr[smallest_child];
          min_arr[smallest_child] = temp;
          bool done = false;
          while (!done && (5*smallest_child+1) < last_index) {
            int new_smallest = 5*smallest_child+1;
            for(int j = new_smallest; j < last_index && j <= 5*smallest_child+5; j++) {
              if(min_arr[new_smallest] > min_arr[j]) {
                new_smallest = j;
              }
            }
            if (min_arr[new_smallest] < min_arr[smallest_child]) {
              temp = min_arr[smallest_child];
              min_arr[smallest_child] = min_arr[new_smallest];
              min_arr[new_smallest] = temp;
            }
            smallest_child = new_smallest;
          }

        }
        current_parent = temp_parent;
        smallest_child = i-1;
      }
    }
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
    if (last_index>=0) {
      int parent = 0;
      min_arr[parent] = -1;
      int smallest_child = 0;
      bool at_leaf = false;
      // traverses all the children of a set parent to find smallest child
      while (!at_leaf) {
        smallest_child = 5*parent+1;
        if (smallest_child > last_index) {
          // shift all the values where the smallest value got deleted
          min_arr[parent] = min_arr[last_index];
          last_index--;
          at_leaf = true;
        }
        else {
          // find smallest child
          for (int i = 1; i <= 5 && 5*parent+i <= last_index; i++) {
            if(min_arr[smallest_child] > min_arr[5*parent+i]) {
              smallest_child = 5*parent+i;
            }
          }
          // replace parent with smallest child
          min_arr[parent] = min_arr[smallest_child];
          parent = smallest_child;
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
    if (last_index >= 0) {
      int max_index = floor((last_index-1)/5) + 1;
      for (int i = max_index+1; i < last_index; i++) {
        if (min_arr[max_index] < min_arr[i]) {
          max_index = i;
        }
      }
      min_arr[max_index] = min_arr[last_index];
      last_index--;
      levelOrder();
    }
    else {
      std::cout << "Min heap is empty\n";
    }
  }
  void MinHeap::findMin(){
    if (last_index >= 0) {
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
    else if(last_index == 0) {
      std::cout << "Max value: " << min_arr[0] << std::endl;
    }
    else {
      std::cout << "Min heap is empty\n";
    }
  }
  void MinHeap::levelOrder(){
    if(last_index < 0) {
      std::cout << "Min heap is empty\n";
    }
    else {
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
  }
