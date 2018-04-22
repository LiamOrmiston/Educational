/*
* LeftistHeap.cpp
* Liam Ormiston
* 4-24-18
* Leftist heap class
*/
#include "LeftistHeap.h"
#include <queue>

template<typename T>
LeftistHeap<T>::LeftistHeap(){
  // initalize LeftistHeap with values from data.txt
  buildHeap();
}
template<typename T>
LeftistHeap<T>::~LeftistHeap(){
  // delete Leftist_arr;
}
template<typename T>
void LeftistHeap<T>::buildHeap(){
  file.open("data.txt");
  int value = 0;
  while (file >> value) {
    insert(value);
  }
}
template<typename T>
LeftistNode<T>* LeftistHeap<T>::concate(LeftistNode<T>* H1, LeftistNode<T>* H2) {

  if(H1 != nullptr && H2 != nullptr) {
    std::cout << "attempting to concate: " <<H1->getValue()<<" with "<<H2->getValue()<< '\n';
    if(H1->getValue() <= H2->getValue()) {
      H1->setRightChildPtr(concate(H1->getRightChildPtr(), H2));
      return H1;
    }
    else {
      H2->setRightChildPtr(concate(H2->getRightChildPtr(), H1));
      return H2;
    }
  }
  else if(H1 == nullptr) {
    return H2;
  }
  else {
    return H1;
  }
}
// insert a value at the end and then rebuild heap
template<typename T>
void LeftistHeap<T>::insert(const int value){
  LeftistNode<T>* new_node = new LeftistNode<T>(value);
  rootPtr = concate(rootPtr, new_node);
}

// delete min
template<typename T>
void LeftistHeap<T>::deleteMin(){
  // min is always the root so we delete then patch at the root
  if (rootPtr != nullptr) {
    // delete root and concate
  }
  else {
    std::cout << "Leftist heap is empty.\n";
  }
}

// find min
template<typename T>
void LeftistHeap<T>::findMin(){
  if (rootPtr != nullptr) {
    std::cout << "Min value is: " << rootPtr->getValue() << '\n';
  }
  else {
    std::cout << "Leftist heap is empty.\n";
  }
}
// prints all nodes in level order
// template<typename T>
// void LeftistHeap<T>::levelOrder(){
//
// }
//Pre, In, Post print methods
template<typename T>
void LeftistHeap<T>::preHelper(LeftistNode<T>* subTreePtr) {

  std::cout << subTreePtr->getValue() << " ";

  if(subTreePtr->getLeftChildPtr() != nullptr) {
    preHelper(subTreePtr->getLeftChildPtr());
  }
  if(subTreePtr->getRightChildPtr() != nullptr) {
    preHelper(subTreePtr->getRightChildPtr());
  }
}
template<typename T>
void LeftistHeap<T>::pre() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty";
  }
  else {
    preHelper(rootPtr);
  }
}

template<typename T>
void LeftistHeap<T>::inHelper(LeftistNode<T>* subTreePtr) {
  if(subTreePtr->getLeftChildPtr() != nullptr) {
    inHelper(subTreePtr->getLeftChildPtr());
  }

  std::cout << subTreePtr->getValue() << " ";

  if(subTreePtr->getRightChildPtr() != nullptr) {
    inHelper(subTreePtr->getRightChildPtr());
  }
}

template<typename T>
void LeftistHeap<T>::in() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty";
  }
  else {
    inHelper(rootPtr);
  }
}

template<typename T>
void LeftistHeap<T>::levelHelper(LeftistNode<T>* subTreePtr) {
  // Print siblings
  // Print children
  if(subTreePtr->getLeftChildPtr() != nullptr) {
    levelHelper(subTreePtr->getLeftChildPtr());
  }
  if(subTreePtr->getRightChildPtr() != nullptr) {
    levelHelper(subTreePtr->getRightChildPtr());
  }

  std::cout << subTreePtr->getValue() << " ";
}

template<typename T>
void LeftistHeap<T>::level() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty";
  }
  else {
    int count = 0;
    int children = 1;
    std::queue<LeftistNode<T>*> Q;
    Q.push(rootPtr);
    while(!Q.empty()) {
      LeftistNode<T>* current = Q.front();
      std::cout << current->getValue() << " ";
      count++;
      if(current->getLeftChildPtr()!=nullptr) {
        Q.push(current->getLeftChildPtr());
      }
      if(current->getRightChildPtr()!=nullptr) {
        Q.push(current->getRightChildPtr());
      }
      Q.pop();
      if(count%children == 0) {
        std::cout << '\n';
        children = children*2;
        count = 0;
      }
    }
    std::cout << '\n';
  }
}


// template<typename T>
// void LeftistHeap<T>::destroyTree(LeftistNode<T>* subTreePtr)
// {
//   //recurse left subtree
//   if(subTreePtr->getLeftChildPtr() != nullptr) {
//     destroyTree(subTreePtr->getLeftChildPtr());
//   }
//
//   //recurse right subtree
//   if(subTreePtr->getRightChildPtr() != nullptr) {
//     destroyTree(subTreePtr->getRightChildPtr());
//   }
//   //deletes node
//   delete subTreePtr;
// }
