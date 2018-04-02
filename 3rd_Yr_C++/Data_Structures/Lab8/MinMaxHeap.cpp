/*
* MinMaxHeap.cpp
* Liam Ormiston
* 4-2-18
* Min-max heap class
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
  // bottom up build
  buildHeap();
}
MinMaxHeap::~MinMaxHeap(){
  // delete minmax_arr;
}
// start at last parent and build back to root (bottom-up)
void MinMaxHeap::buildHeap(){
  int last_parent = floor(last_index/2);
  for (int i = last_parent; i > 0; i--) {
    swap(i);
  }
}
// checks if the given index has grandchildren or not
bool MinMaxHeap::has_gchild(int index) {
  if(index*4 <= last_index) {
    return true;
  }
  else {
    return false;
  }
}
// depending on if the index has a grandchild or not, calls specific swap function
void MinMaxHeap::swap(int index) {
  if(has_gchild(index)) {
    swap_gchild(index);
  }
  else {
    swap_child(index);
  }
}
// index did not have a grandchild so we must swap with a child
void MinMaxHeap::swap_child(int index) {
  int min = index, max = index;
  int child1 = index*2;
  int child2 = index*2+1;
  int temp = minmax_arr[index];

  // no children so we swap for its parent
  if(child1 > last_index) {
    swap(floor(index/2));
  }
  // on min level. must find smallest child to swap with
  else if(isMinLevel(index)) {
    if (minmax_arr[min] >= minmax_arr[child1]) {
      min = child1;
    }
    if (minmax_arr[min] >= minmax_arr[child2] && child2 <= last_index) {
      min = child2;
    }
    // smallest child is smaller than parent.
    if (index != min) {
      // swap
      minmax_arr[index] = minmax_arr[min];
      minmax_arr[min] = temp;
    }
  }
  // on max level so we must find largest child to swap with
  else {
    if (minmax_arr[max] <= minmax_arr[child1]) {
      max = child1;
    }
    if (minmax_arr[max] <= minmax_arr[child2] && child2 <= last_index) {
      max = child2;
    }
    // largest child is larger than parent.
    if (index != max) {
      // swap
      minmax_arr[index] = minmax_arr[max];
      minmax_arr[max] = temp;
    }
  }
}
// index did have a grandchild so we must swap with a grandchild
void MinMaxHeap::swap_gchild(int index) {
  // if given index is on min level, we must find smallest grandchild to swap with
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
    // smallest grandchild is smaller than grandparent
    if (index != min) {
      // swap
      int temp = minmax_arr[index];
      minmax_arr[index] = minmax_arr[min];
      minmax_arr[min] = temp;
    }
  }
  // on max level so we must find largest grandchild to swap with
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
    // largest grandchild is larger than grandparent
    if (index != max) {
      // swap
      int temp = minmax_arr[index];
      minmax_arr[index] = minmax_arr[max];
      minmax_arr[max] = temp;
    }
  }
}
// checks to see if current index is on a min or max level
bool MinMaxHeap::isMinLevel(int index) {
  // math from text book
  int num = floor(log2(index));
  // if even then min level, if odd then max level
  if(fmod(num, 2) == 0) {
    return true;
  }
  else {
    return false;
  }
}
// insert a value at the end and then rebuild heap
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
// delete min
void MinMaxHeap::deleteMin(){
  // min is always the root so we delete then patch at the root
  if (last_index>=1) {
    patch(1);
    levelOrder();
  }
  else {
    std::cout << "Minmax heap is empty.\n";
  }
}
// patch hole with either grandchild if one exists otherwise patch with child
void MinMaxHeap::patch(int index) {
  if(has_gchild(index)) {
    patch_with_gchild(index);
  }
  else {
    patch_with_child(index);
  }
}
// patch hole at index with one of its children
void MinMaxHeap::patch_with_child(int index) {
  int child1 = index*2;
  int child2 = index*2+1;
  int min = child1, max = child1;
  // if there is no children then we must be at last index
  if(child1 > last_index) {
    last_index--;
    swap(index);
  }
  // if on a min level we must find smallest child to patch with
  else if(isMinLevel(index)) {
    if (minmax_arr[min] >= minmax_arr[child2] && child2 <= last_index) {
      min = child2;
    }
    // patch and repair
    minmax_arr[index] = minmax_arr[min];
    minmax_arr[min] = minmax_arr[last_index];
    last_index--;
    swap(min);
  }
  // on max level, must find largest child and patch
  else {
    if (minmax_arr[max] <= minmax_arr[child2] && child2 <= last_index) {
      max = child2;
    }
    // patch and repair
    minmax_arr[index] = minmax_arr[max];
    minmax_arr[max] = minmax_arr[last_index];
    last_index--;
    swap(max);
  }
}
// patch hole at index with one of its grandchildren
void MinMaxHeap::patch_with_gchild(int index) {
  int g_child1 = index*4;
  int g_child2 = index*4+1;
  int g_child3 = index*4+2;
  int g_child4 = index*4+3;
  int min = g_child1, max = g_child1;
  // if on a min level we must find smallest grandchild to patch with
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
    // patch and repair
    minmax_arr[index] = minmax_arr[min];
    minmax_arr[min] = minmax_arr[last_index];
    last_index--;
    swap(min);
  }
  // on a max level, must find largest grandchild to patch with
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
    // patch and repair
    minmax_arr[index] = minmax_arr[max];
    minmax_arr[max] = minmax_arr[last_index];
    last_index--;
    swap(max);
  }
}
// delete max
void MinMaxHeap::deleteMax(){
  // max value is either 2 or 3
  if (last_index > 1) {
    // delete max and patch
    if (minmax_arr[2] < minmax_arr[3] && last_index > 2) {
      // if max doesn't have children then we insert last index
      if(3*2>last_index) {
        minmax_arr[3] = minmax_arr[last_index];
        last_index--;
      }
      else {
        patch(3);
      }
    }
    else {
      // if max doesn't have children then we insert last index
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
// find min
void MinMaxHeap::findMin(){
  // min value is always the root
  if (last_index >= 1) {
    std::cout << "Min value: " << minmax_arr[1] << std::endl;
  }
  else {
    std::cout << "Minmax heap is empty.\n";
  }
}
// find max
void MinMaxHeap::findMax(){
  // max is either 2 or 3
  if (last_index > 1) {
    int max_index = 2;
    if (minmax_arr[max_index] < minmax_arr[3] && last_index > 2) {
      std::cout << "Max value: " << minmax_arr[3] << std::endl;
    }
    else {
      std::cout << "Max value: " << minmax_arr[2] << std::endl;
    }
  }
  // only 1 node so max is the root
  else if(last_index == 1) {
    std::cout << "Max value: " << minmax_arr[1] << std::endl;
  }
  else {
    std::cout << "Minmax heap is empty.\n";
  }
}
// prints all nodes in level order
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
