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
    if(H1->getValue() <= H2->getValue()) {
      H1->setRightChildPtr(concate(H1->getRightChildPtr(), H2));
      setRank(H1);
      if(getRank(H1->getLeftChildPtr()) < getRank(H1->getRightChildPtr())) {
        LeftistNode<T>* temp = H1->getLeftChildPtr();
        H1->setLeftChildPtr(H1->getRightChildPtr());
        H1->setRightChildPtr(temp);
      }
      return H1;
    }
    else {
      H2->setRightChildPtr(concate(H2->getRightChildPtr(), H1));
      setRank(H2);
      if(getRank(H2->getLeftChildPtr()) < getRank(H2->getRightChildPtr())) {
        LeftistNode<T>* temp = H2->getLeftChildPtr();
        H2->setLeftChildPtr(H2->getRightChildPtr());
        H2->setRightChildPtr(temp);
      }
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
    rootPtr = concate(rootPtr->getRightChildPtr(), rootPtr->getLeftChildPtr());
  }
  else {
    std::cout << "Leftist heap is empty.\n";
  }
}

// find min
template<typename T>
void LeftistHeap<T>::setRank(LeftistNode<T>* subTreePtr) {
  int leftRank = 0;
  int rightRank = 0;
  if(subTreePtr->getLeftChildPtr()!=nullptr) {
    leftRank = subTreePtr->getLeftChildPtr()->getRank();
  }
  if(subTreePtr->getRightChildPtr()!=nullptr) {
    rightRank = subTreePtr->getRightChildPtr()->getRank();
  }
  if(leftRank<=rightRank) {
    subTreePtr->setRank(leftRank+1);
  }
  else {
    subTreePtr->setRank(rightRank+1);
  }
}

template<typename T>
int LeftistHeap<T>::getRank(LeftistNode<T>* subTreePtr) {
  if(subTreePtr==nullptr) {
    return 0;
  }
  else {
    return subTreePtr->getRank();
  }
}

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
    std::cout << "Tree is empty\n";
  }
  else {
    preHelper(rootPtr);
  }
  std::cout << '\n';
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
    std::cout << "Tree is empty\n";
  }
  else {
    inHelper(rootPtr);
  }
  std::cout << '\n';
}

template<typename T>
void LeftistHeap<T>::level() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty\n";
  }
  else {
    std::queue<LeftistNode<T>*> Q_current;
    std::queue<LeftistNode<T>*> Q_next;
    std::queue<LeftistNode<T>*> Q_temp;

    Q_current.push(rootPtr);
    while(!Q_current.empty()) {
      LeftistNode<T>* current = Q_current.front();
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
