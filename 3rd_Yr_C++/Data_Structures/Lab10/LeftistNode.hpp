#include "LeftistNode.h"
#include <cstddef>

// default constructor
template<typename T>
LeftistNode<T>::LeftistNode() {
setValue(nullptr);
setRank(nullptr);
setLeftChildPtr(nullptr);
setRightChildPtr(nullptr);
}

// constructor if just the root is given
template<typename T>
LeftistNode<T>::LeftistNode(const T& aValue){
  setValue(aValue);
  setRank(1);
  setLeftChildPtr(nullptr);
  setRightChildPtr(nullptr);
}

// constructor if the root and both children are given
template<typename T>
LeftistNode<T>::LeftistNode(const T& aValue, LeftistNode<T>* leftPtr, LeftistNode<T>* rightPtr) {
  setValue(aValue);
  setLeftChildPtr(leftPtr);
  setRightChildPtr(rightPtr);
}
//destructor
template<typename T>
LeftistNode<T>::~LeftistNode() {
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
}

// Setters
template<typename T>
void LeftistNode<T>::setValue(const T& aValue) {
   value = aValue;
}

template<typename T>
void LeftistNode<T>::setRank(const T& aRank) {
   rank = aRank;
}

template<typename T>
void LeftistNode<T>::setLeftChildPtr(LeftistNode<T>* leftPtr) {
   leftChildPtr = leftPtr;
}

template<typename T>
void LeftistNode<T>::setRightChildPtr(LeftistNode<T>* rightPtr) {
   rightChildPtr = rightPtr;
}

// Getters
template<typename T>
T LeftistNode<T>::getValue() const {
   return value;
}
template<typename T>
T LeftistNode<T>::getRank() const {
   return rank;
}
template<typename T>
LeftistNode<T>* LeftistNode<T>::getLeftChildPtr() const {
   return leftChildPtr;
}
template<typename T>
LeftistNode<T>* LeftistNode<T>::getRightChildPtr() const {
   return rightChildPtr;
}
