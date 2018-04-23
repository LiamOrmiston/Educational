/*
* SkewHeap.cpp
* Liam Ormiston
* 4-24-18
* Skew heap class
*/
#include "SkewHeap.h"
#include <queue>

template<typename T>
SkewHeap<T>::SkewHeap(){
  // initalize SkewHeap with values from data.txt
  buildHeap();
}
template<typename T>
SkewHeap<T>::~SkewHeap(){
  // delete Skew_arr;
}
template<typename T>
void SkewHeap<T>::buildHeap(){
  file.open("data.txt");
  int value = 0;
  while (file >> value) {
    insert(value);
  }
}
template<typename T>
SkewNode<T>* SkewHeap<T>::concate(SkewNode<T>* H1, SkewNode<T>* H2) {

  if(H1 != nullptr && H2 != nullptr) {
    if(H1->getValue() <= H2->getValue()) {
      H1->setRightChildPtr(concate(H1->getRightChildPtr(), H2));
      // Swap
      SkewNode<T>* temp = H1->getLeftChildPtr();
      H1->setLeftChildPtr(H1->getRightChildPtr());
      H1->setRightChildPtr(temp);
      return H1;
    }
    else {
      H2->setRightChildPtr(concate(H2->getRightChildPtr(), H1));
      // Swap
      SkewNode<T>* temp = H2->getLeftChildPtr();
      H2->setLeftChildPtr(H2->getRightChildPtr());
      H2->setRightChildPtr(temp);
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
// insert a value
template<typename T>
void SkewHeap<T>::insert(const int value){
  SkewNode<T>* new_node = new SkewNode<T>(value);
  rootPtr = concate(rootPtr, new_node);
}

// delete min
template<typename T>
void SkewHeap<T>::deleteMin(){
  // min is always the root so we delete then patch at the root
  if (rootPtr != nullptr) {
    // delete root and concate
    rootPtr = concate(rootPtr->getRightChildPtr(), rootPtr->getLeftChildPtr());
  }
  else {
    std::cout << "Skew heap is empty.\n";
  }
}

//Pre, In, Post print methods
template<typename T>
void SkewHeap<T>::preHelper(SkewNode<T>* subTreePtr) {

  std::cout << subTreePtr->getValue() << " ";

  if(subTreePtr->getLeftChildPtr() != nullptr) {
    preHelper(subTreePtr->getLeftChildPtr());
  }
  if(subTreePtr->getRightChildPtr() != nullptr) {
    preHelper(subTreePtr->getRightChildPtr());
  }
}
template<typename T>
void SkewHeap<T>::pre() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty\n";
  }
  else {
    preHelper(rootPtr);
  }
  std::cout << '\n';
}

template<typename T>
void SkewHeap<T>::inHelper(SkewNode<T>* subTreePtr) {
  if(subTreePtr->getLeftChildPtr() != nullptr) {
    inHelper(subTreePtr->getLeftChildPtr());
  }

  std::cout << subTreePtr->getValue() << " ";

  if(subTreePtr->getRightChildPtr() != nullptr) {
    inHelper(subTreePtr->getRightChildPtr());
  }
}

template<typename T>
void SkewHeap<T>::in() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty\n";
  }
  else {
    inHelper(rootPtr);
  }
  std::cout << '\n';
}

template<typename T>
void SkewHeap<T>::level() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty\n";
  }
  else {
    std::queue<SkewNode<T>*> Q_current;
    std::queue<SkewNode<T>*> Q_next;
    std::queue<SkewNode<T>*> Q_temp;

    Q_current.push(rootPtr);
    while(!Q_current.empty()) {
      SkewNode<T>* current = Q_current.front();
      std::cout << current->getValue() << " ";
      if(current->getLeftChildPtr()!=nullptr) {
        Q_next.push(current->getLeftChildPtr());
      }
      if(current->getRightChildPtr()!=nullptr) {
        Q_next.push(current->getRightChildPtr());
      }
      Q_current.pop();
      if(Q_current.empty()) {
        std::cout << '\n';
        Q_temp = Q_current;
        Q_current = Q_next;
        Q_next = Q_temp;
      }
    }
  }
}


// template<typename T>
// void SkewHeap<T>::destroyTree(SkewNode<T>* subTreePtr)
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
