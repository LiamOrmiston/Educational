/*
* LeftistHeap.hpp
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
  destroyTree(rootPtr);
}
template<typename T>
void LeftistHeap<T>::buildHeap(){
  // open the data file and insert each value
  file.open("data.txt");
  int value = 0;
  while (file >> value) {
    insert(value);
  }
}
template<typename T>
LeftistNode<T>* LeftistHeap<T>::concate(LeftistNode<T>* H1, LeftistNode<T>* H2) {

  if(H1 != nullptr && H2 != nullptr) {
    // check which tree has the smaller root. the smaller root will keep its
    // left subtree and will concate the larger root tree with its right subtree
    if(H1->getValue() <= H2->getValue()) {
      H1->setRightChildPtr(concate(H1->getRightChildPtr(), H2));
      // reconfigure rank
      setRank(H1);
      // swap if rank if right child rank is larger than left child rank
      if(getRank(H1->getLeftChildPtr()) < getRank(H1->getRightChildPtr())) {
        LeftistNode<T>* temp = H1->getLeftChildPtr();
        H1->setLeftChildPtr(H1->getRightChildPtr());
        H1->setRightChildPtr(temp);
      }
      return H1;
    }
    else {
      H2->setRightChildPtr(concate(H2->getRightChildPtr(), H1));
      // reconfigure rank
      setRank(H2);
      // swap if rank if right child rank is larger than left child rank
      if(getRank(H2->getLeftChildPtr()) < getRank(H2->getRightChildPtr())) {
        LeftistNode<T>* temp = H2->getLeftChildPtr();
        H2->setLeftChildPtr(H2->getRightChildPtr());
        H2->setRightChildPtr(temp);
      }
      return H2;
    }
  }
  // if one of the tree is a nullptr then just add the other tree by returning it.
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
  // new node created and then concated with the existing tree
  LeftistNode<T>* new_node = new LeftistNode<T>(value);
  rootPtr = concate(rootPtr, new_node);
}

// delete min
template<typename T>
void LeftistHeap<T>::deleteMin(){
  // min is always the root so we delete then concate children
  if (rootPtr != nullptr) {
    // delete root and concate
    LeftistNode<T>* temp = concate(rootPtr->getRightChildPtr(), rootPtr->getLeftChildPtr());
    delete rootPtr;
    rootPtr = temp;
    temp = nullptr;
  }
  else {
    std::cout << "Leftist heap is empty.\n";
  }
}

// rank helper. called after concate
template<typename T>
void LeftistHeap<T>::setRank(LeftistNode<T>* subTreePtr) {
  // finds rank of left and right children
  int leftRank = getRank(subTreePtr->getLeftChildPtr());
  int rightRank = getRank(subTreePtr->getRightChildPtr());

  // sets rank by adding 1 to the minumum child rank
  if(leftRank<=rightRank) {
    subTreePtr->setRank(leftRank+1);
  }
  else {
    subTreePtr->setRank(rightRank+1);
  }
}

template<typename T>
int LeftistHeap<T>::getRank(LeftistNode<T>* subTreePtr) {
  // if subtree is nullptr then rank is 0. otherwise, return the rank stored
  if(subTreePtr==nullptr) {
    return 0;
  }
  else {
    return subTreePtr->getRank();
  }
}

// Pre, In, Post print methods
// Pre: print, recurse-left, recurse-right
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

// In: recurse-left, print, recurse-right
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

// Level: store parent in current-queue and children in next-queue. Once
// current-queue is empty print new line and set next-queue to current-queue
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

// destructor helper
template<typename T>
void LeftistHeap<T>::destroyTree(LeftistNode<T>* subTreePtr) {
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
