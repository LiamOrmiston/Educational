#include <iostream>
#include "TwoThreeTree.h"
#include <fstream>

// Constructor
template<typename T>
TwoThreeTree<T>::TwoThreeTree() {
  rootPtr = nullptr;
}

// Destructor
template<typename T>
TwoThreeTree<T>::~TwoThreeTree() {
  if (rootPtr != nullptr) {
    this->destroyTree(rootPtr); // Call inherited method
  }
}

// Insert
template<typename T>
bool TwoThreeTree<T>::insert(const T& newEntry) {
  TwoThreeNode<T>* new_node = new TwoThreeNode<T>(newEntry);
  if (rootPtr == nullptr) {
    rootPtr = new_node;
  }
  else if(rootPtr->getIsLeaf()){
    if(rootPtr->getValue() < newEntry) {
      // creates new leaf nodes
      TwoThreeNode<T>* new_mid_node = new TwoThreeNode<T>(rootPtr->getValue());
      TwoThreeNode<T>* new_right_node = new TwoThreeNode<T>(newEntry);
      // creates new interior node
      TwoThreeNode<T>* new_intr_node = new TwoThreeNode<T>(rootPtr->getValue(), newEntry, new_mid_node, new_right_node);

      // deletes leaf node rootPtr was set to
      delete rootPtr;
      // sets rootPtr to interior node
      rootPtr = new_intr_node;
    }
    else if(rootPtr->getValue() > newEntry) {
      // creates new leaf nodes
      TwoThreeNode<T>* new_mid_node = new TwoThreeNode<T>(newEntry);
      TwoThreeNode<T>* new_right_node = new TwoThreeNode<T>(rootPtr->getValue());
      // creates new interior node
      TwoThreeNode<T>* new_intr_node = new TwoThreeNode<T>(rootPtr->getValue(), newEntry, new_mid_node, new_right_node);
      // deletes leaf node rootPtr was set to
      delete rootPtr;
      // sets rootPtr to interior node
      rootPtr = new_intr_node;
    }
    else {
      // means that user tried to insert a number that already exists
      return false;
    }
  }
  else {
    rootPtr = (insertInorder(rootPtr, new_node));
  }
	return true;
}

template<typename T>
TwoThreeNode<T>* TwoThreeTree<T>::insertInorder(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* newNodePtr) {
  if(subTreePtr == nullptr) {
    return(newNodePtr);
  }
  else if(subTreePtr->getIsLeaf()) {

  }

  // else if(subTreePtr->getValue() > newNodePtr->getValue()) {
  //   TwoThreeNode<T>* temp = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
  //   subTreePtr -> setLeftChildPtr(temp);
  // }
  // else {
  //   TwoThreeNode<T>* temp = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
  //   subTreePtr -> setRightChildPtr(temp);
  // }
  return(subTreePtr);
}

template<typename T>
bool TwoThreeTree<T>::deleteMin_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr) {
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
bool TwoThreeTree<T>::deleteMin() {
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
      TwoThreeNode<T>* temp = rootPtr->getRightChildPtr();
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
bool TwoThreeTree<T>::deleteMax_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr) {
  if(subTreePtr->getIsLeaf()) {
    std::cout << subTreePtr->getValue() << " has been deleted by deleted\n";
    if(parentPtr->isTwo() && parentPtr->getRightChildPtr() == nullptr) {
      // sets interior node to a leaf node.
      TwoThreeNode<T>* temp_leaf = parentPtr->getLeftChildPtr();
      parentPtr->setIsLeaf(true);
      parentPtr->setValue(temp_leaf->getValue());
      parentPtr->setMinMid(-1);
      parentPtr->setMinRight(-1);
      parentPtr->setLeftChildPtr(nullptr);
      parentPtr->setMidChildPtr(nullptr);
      parentPtr->setRightChildPtr(nullptr);
    }
    else if (parentPtr->isTwo() && parentPtr->getRightChildPtr() != nullptr){
      // sets interior node to a leaf node.
      TwoThreeNode<T>* temp_leaf = parentPtr->getMidChildPtr();
      parentPtr->setIsLeaf(true);
      parentPtr->setValue(temp_leaf->getValue());
      parentPtr->setMinMid(-1);
      parentPtr->setMinRight(-1);
      parentPtr->setLeftChildPtr(nullptr);
      parentPtr->setMidChildPtr(nullptr);
      parentPtr->setRightChildPtr(nullptr);
    }
    // parent has 3 leaves
    else {

    }
  }
  return true;
}


//     if(subTreePtr->getLeftChildPtr() != nullptr) {
//       parentPtr->setRightChildPtr(subTreePtr->getLeftChildPtr());
//       std::cout << subTreePtr->getValue() << " has been deleted by deleted\n";
//       delete subTreePtr;
//
//     }
//     else {
//       std::cout << subTreePtr->getValue() << " has been deleted by deleted\n";
//       parentPtr->setRightChildPtr(nullptr);
//       delete subTreePtr;
//     }
//     return true;
//   }
//   else {
//     return deleteMax_helper(subTreePtr->getRightChildPtr(), subTreePtr);
//   }
// }

template<typename T>
bool TwoThreeTree<T>::deleteMax() {
  if (rootPtr == nullptr) {
    return false;
  }
  else if(rootPtr->getIsLeaf()) {
    std::cout << rootPtr->getValue() << " has been deleted\n";
    delete rootPtr;
    rootPtr = nullptr;
    return true;
  }
  // if right child exists
  else if(rootPtr->getRightChildPtr()) {
    return deleteMax_helper(rootPtr->getRightChildPtr(), rootPtr);
  }
  // if right child doesn't exist
  else {
    return deleteMax_helper(rootPtr->getMidChildPtr(), rootPtr);
  }
}

template<typename T>
bool TwoThreeTree<T>::deleteVal_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr, const T& value) {
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
bool TwoThreeTree<T>::deleteVal(const T& value) {
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
T TwoThreeTree<T>::rightMin(TwoThreeNode<T>* subTreePtr) {
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
bool TwoThreeTree<T>::findMin() {
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
bool TwoThreeTree<T>::findMinHelper(TwoThreeNode<T>* subTreePtr) {
  while (subTreePtr->getLeftChildPtr() != nullptr) {
    subTreePtr = subTreePtr->getLeftChildPtr();
  }
  std::cout << subTreePtr->getValue() << " is the min value\n";
  return true;
}

template<typename T>
bool TwoThreeTree<T>::findMax() {
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
bool TwoThreeTree<T>::findMaxHelper(TwoThreeNode<T>* subTreePtr) {
  while (subTreePtr->getRightChildPtr() != nullptr) {
    subTreePtr = subTreePtr->getRightChildPtr();
  }
  std::cout << subTreePtr->getValue() << " is the max value\n";
  return true;
}

template<typename T>
void TwoThreeTree<T>::getEntry(const T& aKey) {
  TwoThreeNode<T>* temp = findNode(rootPtr, aKey);
  if(temp == nullptr) {
    std::cout << "That value was not found" << std::endl;
  }
  else {
    return(temp->getValue());
  }
}

// level order print methods

template<typename T>
void TwoThreeTree<T>::levelHelper(TwoThreeNode<T>* subTreePtr) {
  if (subTreePtr->getIsLeaf()) {
    std::cout << subTreePtr->getValue() << " ";
  }
  else {
    if(subTreePtr->getLeftChildPtr() != nullptr) {
      levelHelper(subTreePtr->getLeftChildPtr());
    }
    if(subTreePtr->getMidChildPtr() != nullptr) {
      levelHelper(subTreePtr->getMidChildPtr());
    }
    if(subTreePtr->getRightChildPtr() != nullptr) {
      levelHelper(subTreePtr->getRightChildPtr());
    }
  }
}

template<typename T>
void TwoThreeTree<T>::level() {
  if (rootPtr == nullptr) {
    std::cout << "Tree is empty";
  }
  else {
    levelHelper(rootPtr);
  }
}

template<typename T>
void TwoThreeTree<T>::destroyTree(TwoThreeNode<T>* subTreePtr)
{
  //recurse left subtree
  if(subTreePtr->getLeftChildPtr() != nullptr) {
    destroyTree(subTreePtr->getLeftChildPtr());
  }

  //recure middle subtree
  if(subTreePtr->getMidChildPtr() != nullptr) {
    destroyTree(subTreePtr->getMidChildPtr());
  }

  //recurse right subtree
  if(subTreePtr->getRightChildPtr() != nullptr) {
    destroyTree(subTreePtr->getRightChildPtr());
  }

  //deletes node
  delete subTreePtr;
}
