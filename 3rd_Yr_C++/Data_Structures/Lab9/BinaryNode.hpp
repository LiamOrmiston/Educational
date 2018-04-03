/*
 * BinaryNode.hpp
 * Liam Ormiston
 * 4-12-18
 * Binary Node class
 */
#include "BinaryNode.h"
#include <cstddef>

// default constructor
template<typename T>
BinaryNode<T>::BinaryNode() {
setValue(nullptr);
setLeftChildPtr(nullptr);
setRightChildPtr(nullptr);
}

// constructor if just the root is given
template<typename T>
BinaryNode<T>::BinaryNode(const T& aValue){
  setValue(aValue);
  setLeftChildPtr(nullptr);
  setRightChildPtr(nullptr);
}

// constructor if the root and both children are given
template<typename T>
BinaryNode<T>::BinaryNode(const T& aValue, BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr) {
  setValue(aValue);
  setLeftChildPtr(leftPtr);
  setRightChildPtr(rightPtr);
}

template<typename T>
BinaryNode<T>::~BinaryNode() {
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
}

template<typename T>
bool BinaryNode<T>::isLeaf() const {
   return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

// Setters
template<typename T>
void BinaryNode<T>::setValue(const T& aValue) {
   value = aValue;
}

template<typename T>
void BinaryNode<T>::setLeftChildPtr(BinaryNode<T>* leftPtr) {
   leftChildPtr = leftPtr;
}

template<typename T>
void BinaryNode<T>::setRightChildPtr(BinaryNode<T>* rightPtr) {
   rightChildPtr = rightPtr;
}

// Getters
template<typename T>
T BinaryNode<T>::getValue() const {
   return value;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getLeftChildPtr() const {
   return leftChildPtr;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getRightChildPtr() const {
   return rightChildPtr;
}
