/*
* LeftistHeap.cpp
* Liam Ormiston
* 4-24-18
* Leftist heap class
*/
#include "LeftistHeap.h"

LeftistHeap::LeftistHeap(){
  // initalize LeftistHeap with values from data.txt
  file.open("data.txt");
  int value = 0;
  int i = 1;
  while (file >> value) {
    Leftist_arr[i] = value;
    last_index = i;
    i++;
  }
  // bottom up build
  buildHeap();
}
LeftistHeap::~LeftistHeap(){
  // delete Leftist_arr;
}
// start at last parent and build back to root (bottom-up)
void LeftistHeap::buildHeap(){
  int last_parent = floor(last_index/2);
  for (int i = last_parent; i > 0; i--) {
    swap(i);
  }
}

LeftistNode<T>* LeftistHeap::concate(LeftistNode<T>* H1, LeftistNode<T>* H2) {
  if(H1->getValue == nullptr) {
    return H2;
  }
  else if(H2->getValue == nullptr) {
    return H1;
  }
  else {
    if(H1->getValue <= H2->getValue) {
      H1->setRightChildPtr(concate(H1->getRightChildPtr(), H2));
    }
    else {
      H2->setRightChildPtr(concate(H2->getRightChildPtr(), H1));
    }
  }
}
// insert a value at the end and then rebuild heap
void LeftistHeap::insert(const int value){
  LeftistNode<T>* new_node = new LeftistNode<T>(value);
  rootPtr = concate(rootPtr, new_node);
}
// delete min
void LeftistHeap::deleteMin(){
  // min is always the root so we delete then patch at the root
  if (last_index>=1) {
    patch(1);
    levelOrder();
  }
  else {
    std::cout << "Leftist heap is empty.\n";
  }
}

// find min
void LeftistHeap::findMin(){
  // min value is always the root
  if (last_index >= 1) {
    std::cout << "Min value: " << Leftist_arr[1] << std::endl;
  }
  else {
    std::cout << "Leftist heap is empty.\n";
  }
}
// prints all nodes in level order
void LeftistHeap::levelOrder(){
  if(last_index < 1) {
    std::cout << "Leftist heap is empty.\n";
  }
  else {
    int j = 1;
    for (int i = 1; i <= last_index; i++) {
      std::cout << Leftist_arr[i] << " ";
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

template<typename T>
void LeftistHeap<T>::destroyTree(LeftistNode<T>* subTreePtr)
{
  //recurse left subtree
  if(subTreePtr->getLeftChildPtr() != nullptr) {
    destroyTree(subTreePtr->getLeftChildPtr());
  }

  //recurse right subtree
  if(subTreePtr->getRightChildPtr() != nullptr) {
    destroyTree(subTreePtr->getRightChildPtr());
  }
  //deletes node
  delete subTreePtr;
}
