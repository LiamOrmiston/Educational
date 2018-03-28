#include "MaxHeap.h"
#include <math.h>

  MaxHeap::MaxHeap(){
    // initalize MaxHeap with values from data.txt
    file.open("data.txt");
    int value = 0;
    int i = 0;
    while (file >> value) {
      max_arr[i] = value;
      last_index = i;
      i++;
    }
    levelOrder();
    buildHeap();
  }
  MaxHeap::~MaxHeap(){
    // delete max_arr;
  }
  void MaxHeap::buildHeap(){
    // TODO: should go to last parent and then check all the children and work
    // back until get to root
    // last parent: max_arr[floor((last used index in array-1)/5)]
    int smallest_child = last_index;
    int last_parent = floor((last_index-1)/5);
    int current_parent = last_parent;
    int temp_parent = 0;
    for (int i = last_index; i > 0; i--) {
      temp_parent = floor(((i-1)-1)/5);
      if (temp_parent == current_parent && i != 1) {
        if (max_arr[smallest_child] > max_arr[i-1]) {
          std::cout << max_arr[smallest_child] << " is greater than " << max_arr[i-1] << " smallest child is now " << max_arr[i-1] << '\n';
          smallest_child = i-1;
        }
      }
      else {
        std::cout << max_arr[i] << " is the last child of current parent: " << max_arr[current_parent] << '\n';
        if (max_arr[current_parent] > max_arr[smallest_child]) {
          std::cout << max_arr[smallest_child] << " is smaller than " << max_arr[current_parent] << '\n';
          int temp = max_arr[current_parent];
          max_arr[current_parent] = max_arr[smallest_child];
          max_arr[smallest_child] = temp;
          bool done = false;
          while (!done && (5*smallest_child+1) < last_index) {
            int new_smallest = 5*smallest_child+1;
            for(int j = new_smallest; j < last_index && j <= 5*smallest_child+5; j++) {
              if(max_arr[new_smallest] > max_arr[j]) {
                new_smallest = j;
              }
            }
            if (max_arr[new_smallest] < max_arr[smallest_child]) {
              temp = max_arr[smallest_child];
              max_arr[smallest_child] = max_arr[new_smallest];
              max_arr[new_smallest] = temp;
            }
            smallest_child = new_smallest;
          }

        }
        current_parent = temp_parent;
        smallest_child = i-1;
        std::cout << "smallest child is now " << max_arr[smallest_child] << '\n';
        levelOrder();
      }
    }
  }
  void MaxHeap::insert(const int value){
    if (last_index<500) {
      last_index++;
      max_arr[last_index] = value;
      buildHeap();
      levelOrder();
    }
    else {
      std::cout << "Min heap is full. Cannot insert " << value << std::endl;
    }
  }
  void MaxHeap::deleteMin(){
    if (last_index>0) {
      int parent = 0;
      max_arr[parent] = -1;
      int smallest_child = 0;
      bool at_leaf = false;
      // traverses all the children of a set parent to find smallest child
      while (!at_leaf) {
        smallest_child = 5*parent+1;
        if (smallest_child > last_index) {
          // shift all the values where the smallest value got deleted
          max_arr[parent] = max_arr[last_index];
          last_index--;
          at_leaf = true;
        }
        else {
          // find smallest child
          for (int i = 1; i <= 5; i++) {
            if(max_arr[smallest_child] > max_arr[5*parent+i]) {
              smallest_child = 5*parent+i;
            }
          }
          // replace parent with smallest child
          max_arr[parent] = max_arr[smallest_child];
          parent = smallest_child;
          max_arr[parent] = -1;
        }
      }
      levelOrder();
    }
    else {
      std::cout << "Min heap is empty." << std::endl;
    }
  }
  void MaxHeap::deleteMax(){
    if (last_index > 0) {
      int max_index = floor((last_index-1)/5) + 1;
      for (int i = max_index+1; i < last_index; i++) {
        if (max_arr[max_index] < max_arr[i]) {
          max_index = i;
        }
      }
      max_arr[max_index] = max_arr[last_index];
      last_index--;
      levelOrder();
    }
    else {
      std::cout << "Min heap is empty\n";
    }
  }
  void MaxHeap::findMin(){
    if (last_index > 0) {
      std::cout << "Min value: " << max_arr[0] << std::endl;
    }
    else {
      std::cout << "Min heap is empty\n";
    }
  }
  void MaxHeap::findMax(){
    if (last_index > 0) {
      int max_index = floor((last_index-1)/5) + 1;
      for (int i = max_index+1; i < last_index; i++) {
        if (max_arr[max_index] < max_arr[i]) {
          max_index = i;
        }
      }
      std::cout << "Max value: " << max_arr[max_index] << std::endl;
    }
    else {
      std::cout << "Min heap is empty\n";
    }
  }
  void MaxHeap::levelOrder(){
    for (int i = 0; i <= last_index; i++) {
      std::cout << max_arr[i] << " ";
      if (i==0 || i==5 || i==30 || i==155) {
      std::cout << "\n";
      }
      else if (i%5 == 0 && i!=last_index) {
      std::cout << "- ";
      }
    }
    std::cout << "\n";
  }
