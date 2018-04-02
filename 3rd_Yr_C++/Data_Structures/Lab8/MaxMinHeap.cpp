/*
* MaxMinHeap.cpp
* Liam Ormiston
* 4-2-18
* Max-min heap class
*/
#include "MaxMinHeap.h"

MaxMinHeap::MaxMinHeap(){
  // initalize MaxMinHeap with values from data.txt
  file.open("data.txt");
  int value = 0;
  int i = 1;
  while (file >> value) {
    maxmin_arr[i] = value;
    // restructure after each insertion to ensure the tree is always a Max-Min heap
    buildHeap();
    last_index = i;
    i++;
  }
}
MaxMinHeap::~MaxMinHeap(){
  // delete maxmin_arr;
}
// compares inserted value with it's parent.
// swap() handles whether there will be a swap.
void MaxMinHeap::buildHeap(){
  int last_parent = floor(last_index/2);
  for (int i = last_parent; i > 0; i--) {
    swap(i);
  }
}
// checks if the given index has a grand-child or not
bool MaxMinHeap::has_gchild(int index) {
  if(index*4 <= last_index) {
    return true;
  }
  else {
    return false;
  }
}
// calls specific swap function depending on whether the given index has a grand-child
// or not.
void MaxMinHeap::swap(int index) {
  if(has_gchild(index)) {
    swap_gchild(index);
  }
  else {
    swap_child(index);
  }
}
// grand-child does not exist for given index
void MaxMinHeap::swap_child(int index) {
  // initialize variables
  int min = index, max = index;
  int child1 = index*2;
  int child2 = index*2+1;
  int temp = maxmin_arr[index];

  // checks if the given index even has a child
  if(child1 > last_index) {
    //if there is no child then we want to restructure based on the index's parent
    swap(floor(index/2));
  }
  // checks if index is a min or a max level
  else if(isMinLevel(index)) {
    // finds min child for the level
    if (maxmin_arr[min] >= maxmin_arr[child1]) {
      min = child1;
    }
    if (maxmin_arr[min] >= maxmin_arr[child2] && child2 <= last_index) {
      min = child2;
    }
    // checks if the min value is not the given index, meaning that there is a child
    // smaller than the parent (given index)
    if (index != min) {
      //swap
      maxmin_arr[index] = maxmin_arr[min];
      maxmin_arr[min] = temp;
    }
  }
  // we are on a max level
  else {
    // find max child
    if (maxmin_arr[max] <= maxmin_arr[child1]) {
      max = child1;
    }
    if (maxmin_arr[max] <= maxmin_arr[child2] && child2 <= last_index) {
      max = child2;
    }
    // checks if the max value is not the given index, meaning that there is a child
    // larger than the parent (given index)
    if (index != max) {
      // swap
      maxmin_arr[index] = maxmin_arr[max];
      maxmin_arr[max] = temp;
    }
  }
}
// grand-child does exist for given index
void MaxMinHeap::swap_gchild(int index) {
  // checks if index is a min or a max level
  if(isMinLevel(index)) {
    // initialize variables
    int min = index;
    int g_child1 = index*4;
    int g_child2 = index*4+1;
    int g_child3 = index*4+2;
    int g_child4 = index*4+3;

    // finds smallest grandchild
    if (maxmin_arr[min] >= maxmin_arr[g_child1]) {
      min = g_child1;
    }
    if (maxmin_arr[min] >= maxmin_arr[g_child2] && g_child2 <= last_index) {
      min = g_child2;
    }
    if (maxmin_arr[min] >= maxmin_arr[g_child3] && g_child3 <= last_index) {
      min = g_child3;
    }
    if (maxmin_arr[min] >= maxmin_arr[g_child4] && g_child4 <= last_index) {
      min = g_child4;
    }
    // checks to see if swap is necessary
    if (index != min) {
      // swap
      int temp = maxmin_arr[index];
      maxmin_arr[index] = maxmin_arr[min];
      maxmin_arr[min] = temp;
    }
  }
  else {
    // initialize variables
    int max = index;
    int g_child1 = index*4;
    int g_child2 = index*4+1;
    int g_child3 = index*4+2;
    int g_child4 = index*4+3;

    // finds max grandchild
    if (maxmin_arr[max] <= maxmin_arr[g_child1]) {
      max = g_child1;
    }
    if (maxmin_arr[max] <= maxmin_arr[g_child2] && g_child2 <= last_index) {
      max = g_child2;
    }
    if (maxmin_arr[max] <= maxmin_arr[g_child3] && g_child3 <= last_index) {
      max = g_child3;
    }
    if (maxmin_arr[max] <= maxmin_arr[g_child4] && g_child4 <= last_index) {
      max = g_child4;
    }
    // checks if swap is neccessary
    if (index != max) {
      // swap
      int temp = maxmin_arr[index];
      maxmin_arr[index] = maxmin_arr[max];
      maxmin_arr[max] = temp;
    }
  }
}
// Checks if the given index is on a min or max level
bool MaxMinHeap::isMinLevel(int index) {
  // math from textbook
  int num = floor(log2(index));
  // if odd, min level
  if(fmod(num, 2) == 1) {
    return true;
  }
  // even, max level
  else {
    return false;
  }
}
// insertion function
void MaxMinHeap::insert(const int value){
  // checks if full
  if (last_index<500) {
    // add to the back then restructure
    last_index++;
    maxmin_arr[last_index] = value;
    buildHeap();
    levelOrder();
  }
  // full
  else {
    std::cout << "Maxmin heap is full. Cannot insert " << value << std::endl;
  }
}
// Delete Max
void MaxMinHeap::deleteMax(){
  // if there are only 2 nodes, then max will be the last index
  if(last_index == 2) {
    maxmin_arr[1] = maxmin_arr[2];
    last_index--;
    levelOrder();
  }
  // more than 2 nodes or 1 node
  else if (last_index>=1) {
    // deletes root and patches hole
    patch(1);
    levelOrder();
  }
  else {
    std::cout << "Maxmin heap is empty.\n";
  }
}
// patch hold funtion
void MaxMinHeap::patch(int index) {
  // if the given index has a grandchild we patch with a grandchild
  if(has_gchild(index)) {
    patch_with_gchild(index);
  }
  // else we patch with a child
  else {
    patch_with_child(index);
  }
}
// no grandchild so we must patch with child
void MaxMinHeap::patch_with_child(int index) {
  int child1 = index*2;
  int child2 = index*2+1;
  int min = child1, max = child1;
  // if there is no child then we are at the last index and we will delete
  if(child1 > last_index) {
    last_index--;
    swap(index);
  }
  // if on min level we must find smallest child
  else if(isMinLevel(index)) {
    //
    if (maxmin_arr[min] >= maxmin_arr[child2] && child2 <= last_index) {
      min = child2;
    }
    // swap with smallest child
    maxmin_arr[index] = maxmin_arr[min];
    maxmin_arr[min] = maxmin_arr[last_index];
    last_index--;
    swap(min);
  }
  // on max level, must find largest child
  else {
    if (maxmin_arr[max] <= maxmin_arr[child2] && child2 <= last_index) {
      max = child2;
    }
    // swap with largest child
    maxmin_arr[index] = maxmin_arr[max];
    maxmin_arr[max] = maxmin_arr[last_index];
    last_index--;
    swap(max);
  }
}
// grandchildren exist
void MaxMinHeap::patch_with_gchild(int index) {
  int g_child1 = index*4;
  int g_child2 = index*4+1;
  int g_child3 = index*4+2;
  int g_child4 = index*4+3;
  int min = g_child1, max = g_child1;
  // if on min level we must find smallest grandchild
  if(isMinLevel(index)) {
    if (maxmin_arr[min] >= maxmin_arr[g_child2] && g_child2 <= last_index) {
      min = g_child2;
    }
    if (maxmin_arr[min] >= maxmin_arr[g_child3] && g_child3 <= last_index) {
      min = g_child3;
    }
    if (maxmin_arr[min] >= maxmin_arr[g_child4] && g_child4 <= last_index) {
      min = g_child4;
    }
    // swap
    maxmin_arr[index] = maxmin_arr[min];
    maxmin_arr[min] = maxmin_arr[last_index];
    last_index--;
    swap(min);
  }
  // on max level, must find largest grandchild
  else {
    if (maxmin_arr[max] <= maxmin_arr[g_child2] && g_child2 <= last_index) {
      max = g_child2;
    }
    if (maxmin_arr[max] <= maxmin_arr[g_child3] && g_child3 <= last_index) {
      max = g_child3;
    }
    if (maxmin_arr[max] <= maxmin_arr[g_child4] && g_child4 <= last_index) {
      max = g_child4;
    }
    // swap
    maxmin_arr[index] = maxmin_arr[max];
    maxmin_arr[max] = maxmin_arr[last_index];
    last_index--;
    swap(max);
  }
}
// delete min
void MaxMinHeap::deleteMin(){
  // finds smallest node: either 2 or 3
  if (last_index > 1) {
    if (maxmin_arr[2] > maxmin_arr[3] && last_index > 2) {
      // delete and patch
      if(3*2>last_index) {
        maxmin_arr[3] = maxmin_arr[last_index];
        last_index--;
      }
      else {
        patch(3);
      }
    }
    else {
      // node doesn't have children to patch with so we use the last index
      if(2*2>last_index) {
        maxmin_arr[2] = maxmin_arr[last_index];
        last_index--;
      }
      else {
        patch(2);
      }
    }
    levelOrder();
  }
  // only one node
  else if (last_index == 1) {
    last_index--;
    std::cout << "Maxmin heap is empty.\n";
  }
  // empty
  else {
    std::cout << "Maxmin heap is empty.\n";
  }
}
// find max
void MaxMinHeap::findMax(){
  // max is always the root
  if (last_index >= 1) {
    std::cout << "Max value: " << maxmin_arr[1] << std::endl;
  }
  else {
    std::cout << "Maxmin heap is empty.\n";
  }
}
// find min
void MaxMinHeap::findMin(){
  // finds smallest node: either 2 or 3
  if (last_index > 1) {
    if (maxmin_arr[2] > maxmin_arr[3] && last_index > 2) {
      std::cout << "Min value: " << maxmin_arr[3] << std::endl;
    }
    else {
      std::cout << "Min value: " << maxmin_arr[2] << std::endl;
    }
  }
  else if(last_index == 1) {
    std::cout << "Min value: " << maxmin_arr[1] << std::endl;
  }
  else {
    std::cout << "Maxmin heap is empty.\n";
  }
}
// prints all nodes in level order
void MaxMinHeap::levelOrder(){
  if(last_index < 1) {
    std::cout << "Maxmin heap is empty.\n";
  }
  else {
    int j = 1;
    for (int i = 1; i <= last_index; i++) {
      std::cout << maxmin_arr[i] << " ";
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
