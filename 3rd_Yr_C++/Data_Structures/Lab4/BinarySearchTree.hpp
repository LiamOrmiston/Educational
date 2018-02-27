#include <iostream>
#include "BinarySearchTree.h"
#include <fstream>

// Constructor
template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
  rootPtr = nullptr;
}

// Destructor
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  if (rootPtr != nullptr) {
    this->destroyTree(rootPtr); // Call inherited method
  }
}

// Insert
template<typename T>
bool BinarySearchTree<T>::add(const T& newEntry) {
  BinaryNode<T>* new_node = new BinaryNode<T>(newEntry);
  rootPtr = (insertInorder(rootPtr, new_node));
	return true;
}

template<typename T>
bool BinarySearchTree<T>::deleteMin_helper(BinaryNode<T>* subTreePtr, BinaryNode<T>* parentPtr) {
  if(subTreePtr->getLeftChildPtr() == nullptr) {
    if(subTreePtr->getRightChildPtr() != nullptr) {
      parentPtr->setLeftChildPtr(subTreePtr->getRightChildPtr());
      std::cout << subTreePtr->getValue() << " has been deleted by deleted\n";
      delete subTreePtr;

    }
    else {
      std::cout << subTreePtr->getValue() << " has been deleted by deleted\n";
      parentPtr->setLeftChildPtr(nullptr);
      delete subTreePtr;
    }
    return true;
  }
  else {
    return deleteMin_helper(subTreePtr->getLeftChildPtr(), subTreePtr);
  }
}
template<typename T>
bool BinarySearchTree<T>::deleteMin() {
  if(rootPtr == nullptr) {
    return false;
  }
  else if(rootPtr->getLeftChildPtr() == nullptr) {
    if(rootPtr->getRightChildPtr() == nullptr) {
      std::cout << rootPtr->getValue() << " has been deleted by deleted\n";
      delete rootPtr;
      rootPtr = nullptr;
      return true;
    }
    else {
      BinaryNode<T>* temp = rootPtr->getRightChildPtr();
      std::cout << rootPtr->getValue() << " has been deleted by deleted\n";
      delete rootPtr;
      rootPtr = temp;
      return true;
    }
  }
  else {
    return deleteMin_helper(rootPtr->getLeftChildPtr(), rootPtr);
  }
}

template<typename T>
bool BinarySearchTree<T>::deleteMax_helper(BinaryNode<T>* subTreePtr, BinaryNode<T>* parentPtr) {
  if(subTreePtr->getRightChildPtr() == nullptr) {
    if(subTreePtr->getLeftChildPtr() != nullptr) {
      parentPtr->setRightChildPtr(subTreePtr->getLeftChildPtr());
      std::cout << subTreePtr->getValue() << " has been deleted by deleted\n";
      delete subTreePtr;

    }
    else {
      std::cout << subTreePtr->getValue() << " has been deleted by deleted\n";
      parentPtr->setRightChildPtr(nullptr);
      delete subTreePtr;
    }
    return true;
  }
  else {
    return deleteMax_helper(subTreePtr->getRightChildPtr(), subTreePtr);
  }
}
template<typename T>
bool BinarySearchTree<T>::deleteMax() {
  if (rootPtr == nullptr) {
    return false;
  }
  else if(rootPtr->getRightChildPtr() == nullptr) {
    if(rootPtr->getLeftChildPtr() == nullptr) {
      std::cout << rootPtr->getValue() << " has been deleted\n";
      delete rootPtr;
      rootPtr = nullptr;
      return true;
    }
    else {
      BinaryNode<T>* temp = rootPtr->getLeftChildPtr();
      std::cout << rootPtr->getValue() << " has been deleted\n";
      delete rootPtr;
      rootPtr = temp;
      return true;
    }
  }
  else {
    return deleteMax_helper(rootPtr->getRightChildPtr(), rootPtr);
  }
}

template<typename T>
bool BinarySearchTree<T>::deleteVal_helper(BinaryNode<T>* subTreePtr, BinaryNode<T>* parentPtr, const T& value) {
  if(subTreePtr->getValue() == value) {
    if(subTreePtr->getRightChildPtr() == nullptr && subTreePtr->getLeftChildPtr() != nullptr) {
      return deleteMax_helper(subTreePtr, parentPtr);
    }
    else if(subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() != nullptr) {
      return deleteMin_helper(subTreePtr, parentPtr);
    }
    else if(subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() != nullptr) {
      subTreePtr->setValue(rightMin(subTreePtr->getRightChildPtr()));
      return deleteMin_helper(subTreePtr->getRightChildPtr(), subTreePtr);
    }
    else {
      return deleteMin_helper(subTreePtr, parentPtr);
    }
  }
  else if (subTreePtr->getValue() > value) {
    return deleteVal_helper(subTreePtr->getLeftChildPtr(), subTreePtr, value);
  }
  else if (subTreePtr->getValue() < value) {
    return deleteVal_helper(subTreePtr->getRightChildPtr(), subTreePtr, value);
  }
  else {
    return false;
  }
}
template<typename T>
bool BinarySearchTree<T>::deleteVal(const T& value) {
  if(rootPtr->getValue() == value) {
    if(rootPtr->getRightChildPtr() == nullptr && rootPtr->getLeftChildPtr() != nullptr) {
      return deleteMax();
    }
    else if(rootPtr->getLeftChildPtr() == nullptr && rootPtr->getRightChildPtr() != nullptr) {
      return deleteMin();
    }
    else if(rootPtr->getLeftChildPtr() != nullptr && rootPtr->getRightChildPtr() != nullptr) {
      rootPtr->setValue(rightMin(rootPtr->getRightChildPtr()));
      return deleteMin_helper(rootPtr->getRightChildPtr(), rootPtr);
    }
    else {
      return deleteMin();
    }
  }
  else if (rootPtr->getValue() > value) {
    return deleteVal_helper(rootPtr->getLeftChildPtr(), rootPtr, value);
  }
  else if (rootPtr->getValue() < value) {
    return deleteVal_helper(rootPtr->getRightChildPtr(), rootPtr, value);
  }
  else {
    return false;
  }
}

template<typename T>
T BinarySearchTree<T>::rightMin(BinaryNode<T>* subTreePtr) {
  if(subTreePtr->getLeftChildPtr() != nullptr) {
    return rightMin(subTreePtr->getLeftChildPtr());
  }
  else {
    T value = subTreePtr->getValue();
    return value;
  }
}

// find methods
template<typename T>
bool BinarySearchTree<T>::findMin() {
  if(rootPtr == nullptr) {
    return false;
  }
  else if (rootPtr->getLeftChildPtr() == nullptr) {
    std::cout << rootPtr->getValue() << " is the min value\n";
    return true;
  }
  else {
    return findMinHelper(rootPtr->getLeftChildPtr());
  }
}
template<typename T>
bool BinarySearchTree<T>::findMinHelper(BinaryNode<T>* subTreePtr) {
  while (subTreePtr->getLeftChildPtr() != nullptr) {
    subTreePtr = subTreePtr->getLeftChildPtr();
  }
  std::cout << subTreePtr->getValue() << " is the min value\n";
  return true;
}

template<typename T>
bool BinarySearchTree<T>::findMax() {
  if(rootPtr == nullptr) {
    return false;
  }
  else if (rootPtr->getRightChildPtr() == nullptr) {
    std::cout << rootPtr->getValue() << " is the max value\n";
    return true;
  }
  else {
    return findMaxHelper(rootPtr->getRightChildPtr());
  }
}
template<typename T>
bool BinarySearchTree<T>::findMaxHelper(BinaryNode<T>* subTreePtr) {
  while (subTreePtr->getRightChildPtr() != nullptr) {
    subTreePtr = subTreePtr->getRightChildPtr();
  }
  std::cout << subTreePtr->getValue() << " is the max value\n";
  return true;
}

template<typename T>
void BinarySearchTree<T>::getEntry(const T& aKey) {
  BinaryNode<T>* temp = findNode(rootPtr, aKey);
  if(temp == nullptr) {
    std::cout << "That value was not found" << std::endl;
  }
  else {
    return(temp->getValue());
  }
}

//Pre, In, Post print methods
template<typename T>
void BinarySearchTree<T>::preHelper(BinaryNode<T>* subTreePtr) {

  std::cout << subTreePtr->getValue() << " ";

  if(subTreePtr->getLeftChildPtr() != nullptr) {
    preHelper(subTreePtr->getLeftChildPtr());
  }
  if(subTreePtr->getRightChildPtr() != nullptr) {
    preHelper(subTreePtr->getRightChildPtr());
  }
}
template<typename T>
void BinarySearchTree<T>::pre() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty";
  }
  else {
    preHelper(rootPtr);
  }
}

template<typename T>
void BinarySearchTree<T>::inHelper(BinaryNode<T>* subTreePtr) {
  if(subTreePtr->getLeftChildPtr() != nullptr) {
    inHelper(subTreePtr->getLeftChildPtr());
  }

  std::cout << subTreePtr->getValue() << " ";

  if(subTreePtr->getRightChildPtr() != nullptr) {
    inHelper(subTreePtr->getRightChildPtr());
  }
}

template<typename T>
void BinarySearchTree<T>::in() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty";
  }
  else {
    inHelper(rootPtr);
  }
}

template<typename T>
void BinarySearchTree<T>::postHelper(BinaryNode<T>* subTreePtr) {
  if(subTreePtr->getLeftChildPtr() != nullptr) {
    postHelper(subTreePtr->getLeftChildPtr());
  }
  if(subTreePtr->getRightChildPtr() != nullptr) {
    postHelper(subTreePtr->getRightChildPtr());
  }

  std::cout << subTreePtr->getValue() << " ";
}

template<typename T>
void BinarySearchTree<T>::post() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty";
  }
  else {
    postHelper(rootPtr);
  }
}

template<typename T>
void BinarySearchTree<T>::destroyTree(BinaryNode<T>* subTreePtr)
{
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

template<typename T>
BinaryNode<T>* BinarySearchTree<T>::insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr) {
  if(subTreePtr == nullptr) {
    return(newNodePtr);
  }
  else if(subTreePtr->getValue() > newNodePtr->getValue()) {
    BinaryNode<T>* temp = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
    subTreePtr -> setLeftChildPtr(temp);
  }
  else {
    BinaryNode<T>* temp = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
    subTreePtr -> setRightChildPtr(temp);
  }
  return(subTreePtr);
}
