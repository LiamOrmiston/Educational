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
  }
  MinHeap::~MinHeap(){
    // delete min_arr;
  }
  void MinHeap::buildHeap(){
    std::cout << "buildHeap() still needs to be implemented\n";
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
      for (int i = 0; i < last_index; i++) {
        min_arr[i] = min_arr[i+1];
      }
      last_index--;
      buildHeap();
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
