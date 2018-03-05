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

// interior node constructor for root
template<typename T>
TwoThreeNode<T>::TwoThreeNode(const T& minMidValue, const T& minRightValue, TwoThreeNode<T>* midPtr, TwoThreeNode<T>* rightPtr) {
  setValue(-1);
  setMinMid(minMidValue);
  setMinRight(minRightValue);
  setLeftChildPtr(nullptr);
  setMidChildPtr(midPtr);
  setRightChildPtr(rightPtr);
  setParentPtr(nullptr);
  setIsLeaf(false);
}

// interior node constructor
template<typename T>
TwoThreeNode<T>::TwoThreeNode(const T& minMidValue, const T& minRightValue, TwoThreeNode<T>* midPtr, TwoThreeNode<T>* rightPtr, TwoThreeNode<T>* parentPtr) {
  setValue(-1);
  setMinMid(minMidValue);
  setMinRight(minRightValue);
  setLeftChildPtr(nullptr);
  setMidChildPtr(midPtr);
  setRightChildPtr(rightPtr);
  setParentPtr(parentPtr);
  setIsLeaf(false);
}

template<typename T>
TwoThreeNode<T>::~TwoThreeNode() {
  // not sure what a destructor looks like... 
}

template<typename T>
bool TwoThreeNode<T>::isTwo() {
  if(getIsLeaf()) {
    return false;
  }
  else if(getLeftChildPtr() && getMidChildPtr() && getRightChildPtr()) {
    return false;
  }
  else {
    return true;
  }
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
