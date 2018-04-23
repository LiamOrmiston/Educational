/*
* SkewHeap.hpp
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
  destroyTree(rootPtr);
}
template<typename T>
void SkewHeap<T>::buildHeap(){
  // open the data file and insert each value
  file.open("data.txt");
  int value = 0;
  while (file >> value) {
    insert(value);
  }
}
template<typename T>
SkewNode<T>* SkewHeap<T>::concate(SkewNode<T>* H1, SkewNode<T>* H2) {

  if(H1 != nullptr && H2 != nullptr) {
    // check which tree has the smaller root. the smaller root will keep its
    // left subtree and will concate the larger root tree with its right subtree
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
  // new node created and then concated with the existing tree
  SkewNode<T>* new_node = new SkewNode<T>(value);
  rootPtr = concate(rootPtr, new_node);
}

// delete min
template<typename T>
void SkewHeap<T>::deleteMin(){
  // min is always the root so we delete then concate children
  if (rootPtr != nullptr) {
    // delete root and concate
    SkewNode<T>* temp = concate(rootPtr->getRightChildPtr(), rootPtr->getLeftChildPtr());
    delete rootPtr;
    rootPtr = temp;
    temp = nullptr;
  }
  else {
    std::cout << "Skew heap is empty.\n";
  }
}

// Pre, In, Post print methods
// Pre: print, recurse-left, recurse-right
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

// In: recurse-left, print, recurse-right
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

// Level: store parent in current-queue and children in next-queue. Once
// current-queue is empty print new line and set next-queue to current-queue
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

// destructor helper
template<typename T>
void SkewHeap<T>::destroyTree(SkewNode<T>* subTreePtr) {
  if (subTreePtr != nullptr) {
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
}
