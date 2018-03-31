/*
 * MinMaxHeap.cpp
 * Liam Ormiston
 * 4-2-18
 * Min heap class
 */
#include "MinMaxHeap.h"
#include <math.h>

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
    int smallest_child = last_index;
    int last_parent = floor((last_index-1)/5);
    int current_parent = last_parent;
    int temp_parent = 0;
    for (int i = last_index; i > 1; i--) {
      temp_parent = floor(((i-1)-1)/5);
      if (temp_parent == current_parent && i != 1) {
        if (minmax_arr[smallest_child] > minmax_arr[i-1]) {
          smallest_child = i-1;
        }
      }
      else {
        if (minmax_arr[current_parent] > minmax_arr[smallest_child]) {
          int temp = minmax_arr[current_parent];
          minmax_arr[current_parent] = minmax_arr[smallest_child];
          minmax_arr[smallest_child] = temp;
          bool done = false;
          while (!done && (5*smallest_child+1) < last_index) {
            int new_smallest = 5*smallest_child+1;
            for(int j = new_smallest; j < last_index && j <= 5*smallest_child+5; j++) {
              if(minmax_arr[new_smallest] > minmax_arr[j]) {
                new_smallest = j;
              }
            }
            if (minmax_arr[new_smallest] < minmax_arr[smallest_child]) {
              temp = minmax_arr[smallest_child];
              minmax_arr[smallest_child] = minmax_arr[new_smallest];
              minmax_arr[new_smallest] = temp;
            }
            smallest_child = new_smallest;
          }

        }
        current_parent = temp_parent;
        smallest_child = i-1;
      }
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
  // TODO: make levelOrder mathematic
  void MinMaxHeap::levelOrder(){
    if(last_index < 1) {
      std::cout << "Minmax heap is empty\n";
    }
    else {
      for (int i = 1; i <= last_index; i++) {
        std::cout << minmax_arr[i] << " ";
        if (i==1 || i==5 || i==30 || i==155) {
        std::cout << "\n";
        }
        else if (i%5 == 1 && i!=last_index) {
        std::cout << "- ";
        }
      }
      std::cout << "\n";
    }
  }
