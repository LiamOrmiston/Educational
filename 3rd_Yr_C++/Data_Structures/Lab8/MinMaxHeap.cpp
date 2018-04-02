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
  int min = index, max = index;
  int child1 = index*2;
  int child2 = index*2+1;
  int temp = minmax_arr[index];

  if(child1 > last_index) {
    swap(floor(index/2));
  }
  else if(isMinLevel(index)) {
    if (minmax_arr[min] >= minmax_arr[child1]) {
      min = child1;
    }
    if (minmax_arr[min] >= minmax_arr[child2] && child2 <= last_index) {
      min = child2;
    }
    if (index != min) {
      minmax_arr[index] = minmax_arr[min];
      minmax_arr[min] = temp;
    }
  }
  else {
    if (minmax_arr[max] <= minmax_arr[child1]) {
      max = child1;
    }
    if (minmax_arr[max] <= minmax_arr[child2] && child2 <= last_index) {
      max = child2;
    }
    if (index != max) {
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

    if (minmax_arr[min] >= minmax_arr[g_child1]) {
      min = g_child1;
    }
    if (minmax_arr[min] >= minmax_arr[g_child2] && g_child2 <= last_index) {
      min = g_child2;
    }
    if (minmax_arr[min] >= minmax_arr[g_child3] && g_child3 <= last_index) {
      min = g_child3;
    }
    if (minmax_arr[min] >= minmax_arr[g_child4] && g_child4 <= last_index) {
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

    if (minmax_arr[max] <= minmax_arr[g_child1]) {
      max = g_child1;
    }
    if (minmax_arr[max] <= minmax_arr[g_child2] && g_child2 <= last_index) {
      max = g_child2;
    }
    if (minmax_arr[max] <= minmax_arr[g_child3] && g_child3 <= last_index) {
      max = g_child3;
    }
    if (minmax_arr[max] <= minmax_arr[g_child4] && g_child4 <= last_index) {
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
    patch(1);
    levelOrder();
  }
  else {
    std::cout << "Minmax heap is empty.\n";
  }
}
void MinMaxHeap::patch(int index) {
  if(has_gchild(index)) {
    patch_with_gchild(index);
  }
  else {
    patch_with_child(index);
  }
}
void MinMaxHeap::patch_with_child(int index) {
  int child1 = index*2;
  int child2 = index*2+1;
  int min = child1, max = child1;
  if(child1 > last_index) {
    last_index--;
    swap(index);
  }
  else if(isMinLevel(index)) {
    if (minmax_arr[min] >= minmax_arr[child2] && child2 <= last_index) {
      min = child2;
    }
    minmax_arr[index] = minmax_arr[min];
    minmax_arr[min] = minmax_arr[last_index];
    last_index--;
    swap(min);
  }
  else {
    if (minmax_arr[max] <= minmax_arr[child2] && child2 <= last_index) {
      max = child2;
    }
    minmax_arr[index] = minmax_arr[max];
    minmax_arr[max] = minmax_arr[last_index];
    last_index--;
    swap(max);
  }
}
void MinMaxHeap::patch_with_gchild(int index) {
  int g_child1 = index*4;
  int g_child2 = index*4+1;
  int g_child3 = index*4+2;
  int g_child4 = index*4+3;
  int min = g_child1, max = g_child1;

  if(isMinLevel(index)) {
    if (minmax_arr[min] >= minmax_arr[g_child2] && g_child2 <= last_index) {
      min = g_child2;
    }
    if (minmax_arr[min] >= minmax_arr[g_child3] && g_child3 <= last_index) {
      min = g_child3;
    }
    if (minmax_arr[min] >= minmax_arr[g_child4] && g_child4 <= last_index) {
      min = g_child4;
    }
    minmax_arr[index] = minmax_arr[min];
    minmax_arr[min] = minmax_arr[last_index];
    last_index--;
    swap(min);
  }
  else {
    if (minmax_arr[max] <= minmax_arr[g_child2] && g_child2 <= last_index) {
      max = g_child2;
    }
    if (minmax_arr[max] <= minmax_arr[g_child3] && g_child3 <= last_index) {
      max = g_child3;
    }
    if (minmax_arr[max] <= minmax_arr[g_child4] && g_child4 <= last_index) {
      max = g_child4;
    }
    minmax_arr[index] = minmax_arr[max];
    minmax_arr[max] = minmax_arr[last_index];
    last_index--;
    swap(max);
  }
}
void MinMaxHeap::deleteMax(){
  if (last_index > 1) {
    if (minmax_arr[2] < minmax_arr[3] && last_index > 2) {
      if(3*2>last_index) {
        minmax_arr[3] = minmax_arr[last_index];
        last_index--;
      }
      else {
        patch(3);
      }
    }
    else {
      if(2*2>last_index) {
        minmax_arr[2] = minmax_arr[last_index];
        last_index--;
      }
      else {
        patch(2);
      }
    }
    levelOrder();
  }
  else if (last_index == 1) {
    last_index--;
    std::cout << "Minmax heap is empty.\n";
  }
  else {
    std::cout << "Minmax heap is empty.\n";
  }
}
void MinMaxHeap::findMin(){
  if (last_index >= 1) {
    std::cout << "Min value: " << minmax_arr[1] << std::endl;
  }
  else {
    std::cout << "Minmax heap is empty.\n";
  }
}
void MinMaxHeap::findMax(){
  if (last_index > 1) {
    int max_index = 2;
    if (minmax_arr[max_index] < minmax_arr[3] && last_index > 2) {
      std::cout << "Max value: " << minmax_arr[3] << std::endl;
    }
    else {
      std::cout << "Max value: " << minmax_arr[2] << std::endl;
    }
  }
  else if(last_index == 1) {
    std::cout << "Max value: " << minmax_arr[1] << std::endl;
  }
  else {
    std::cout << "Minmax heap is empty.\n";
  }
}
void MinMaxHeap::levelOrder(){
  if(last_index < 1) {
    std::cout << "Minmax heap is empty.\n";
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
