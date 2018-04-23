#include "SkewNode.h"
#include <cstddef>

// default constructor
template<typename T>
SkewNode<T>::SkewNode() {
setValue(nullptr);
setLeftChildPtr(nullptr);
setRightChildPtr(nullptr);
}

// constructor if just the root is given
template<typename T>
SkewNode<T>::SkewNode(const T& aValue){
  setValue(aValue);
  setLeftChildPtr(nullptr);
  setRightChildPtr(nullptr);
}

// constructor if the root and both children are given
template<typename T>
SkewNode<T>::SkewNode(const T& aValue, SkewNode<T>* leftPtr, SkewNode<T>* rightPtr) {
  setValue(aValue);
  setLeftChildPtr(leftPtr);
  setRightChildPtr(rightPtr);
}

template<typename T>
SkewNode<T>::~SkewNode() {
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
}

// Setters
template<typename T>
void SkewNode<T>::setValue(const T& aValue) {
   value = aValue;
}

template<typename T>
void SkewNode<T>::setLeftChildPtr(SkewNode<T>* leftPtr) {
   leftChildPtr = leftPtr;
}

template<typename T>
void SkewNode<T>::setRightChildPtr(SkewNode<T>* rightPtr) {
   rightChildPtr = rightPtr;
}

// Getters
template<typename T>
T SkewNode<T>::getValue() const {
   return value;
}
template<typename T>
SkewNode<T>* SkewNode<T>::getLeftChildPtr() const {
   return leftChildPtr;
}
template<typename T>
SkewNode<T>* SkewNode<T>::getRightChildPtr() const {
   return rightChildPtr;
}
