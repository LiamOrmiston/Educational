#include "TwoThreeNode.h"
#include <cstddef>

// default constructor
template<typename T>
TwoThreeNode<T>::TwoThreeNode() {
setValue(nullptr);
setLeftChildPtr(nullptr);
setMidChildPtr(nullptr);
setRightChildPtr(nullptr);
}

// leaf constructor
template<typename T>
TwoThreeNode<T>::TwoThreeNode(const T& aValue){
  setValue(aValue);
  setMinMid(-1);
  setMinRight(-1);
  setLeftChildPtr(nullptr);
  setMidChildPtr(nullptr);
  setRightChildPtr(nullptr);
  setParentPtr(nullptr);
  setIsLeaf(true);
}

// 3 child constructor
// template<typename T>
// TwoThreeNode<T>::TwoThreeNode(const T& aValue, TwoThreeNode<T>* leftPtr, TwoThreeNode<T>* midPtrm, TwoThreeNode<T>* rightPtr) {
//   setValue(aValue);
//   setLeftChildPtr(leftPtr);
//   setMidChildPtr(midPtr);
//   setRightChildPtr(rightPtr);
// }

template<typename T>
TwoThreeNode<T>::~TwoThreeNode() {
  leftChildPtr = nullptr;
  midChildPtr = nullptr;
  rightChildPtr = nullptr;
}

// Setters
template<typename T>
void TwoThreeNode<T>::setValue(const T& aValue) {
   value = aValue;
}

template<typename T>
void TwoThreeNode<T>::setMinMid(const T& aValue) {
   minMid = aValue;
}

template<typename T>
void TwoThreeNode<T>::setMinRight(const T& aValue) {
   minRight = aValue;
}

template<typename T>
void TwoThreeNode<T>::setIsLeaf(const bool aValue) {
   isLeaf = aValue;
}

template<typename T>
void TwoThreeNode<T>::setLeftChildPtr(TwoThreeNode<T>* leftPtr) {
   leftChildPtr = leftPtr;
}

template<typename T>
void TwoThreeNode<T>::setMidChildPtr(TwoThreeNode<T>* midPtr) {
   midChildPtr = midPtr;
}

template<typename T>
void TwoThreeNode<T>::setRightChildPtr(TwoThreeNode<T>* rightPtr) {
   rightChildPtr = rightPtr;
}

template<typename T>
void TwoThreeNode<T>::setParentPtr(TwoThreeNode<T>* aParentPtr) {
   parentPtr = aParentPtr;
}

// Getters
template<typename T>
T TwoThreeNode<T>::getValue() const {
   return value;
}

template<typename T>
T TwoThreeNode<T>::getMinMid() const {
   return minMid;
}

template<typename T>
T TwoThreeNode<T>::getMinRight() const {
   return minRight;
}

template<typename T>
bool TwoThreeNode<T>::getIsLeaf() const {
   return isLeaf;
}

template<typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getLeftChildPtr() const {
   return leftChildPtr;
}

template<typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getMidChildPtr() const {
   return midChildPtr;
}

template<typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getRightChildPtr() const {
   return rightChildPtr;
}

template<typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getParentPtr() const {
   return parentPtr;
}
