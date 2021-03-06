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
  TwoThreeNode<T>* new_node = new TwoThreeNode<T>(newEntry, rootPtr);
  if (rootPtr == nullptr) {
    new_node->setParentPtr(nullptr);
    rootPtr = new_node;
  }
  else if(rootPtr->getIsLeaf()){
    if(rootPtr->getValue() < newEntry) {
      // creates new leaf nodes
      TwoThreeNode<T>* new_mid_node = new TwoThreeNode<T>(rootPtr->getValue());
      TwoThreeNode<T>* new_right_node = new TwoThreeNode<T>(newEntry);
      // creates new interior node from existing leaf node
      rootPtr->convertToInterior(rootPtr->getValue(), newEntry, nullptr, new_mid_node, new_right_node);
      rootPtr->setParentPtr(nullptr);
      new_mid_node->setParentPtr(rootPtr);
      new_right_node->setParentPtr(rootPtr);
    }
    else if(rootPtr->getValue() > newEntry) {
      // creates new leaf nodes
      TwoThreeNode<T>* new_left_node = new TwoThreeNode<T>(newEntry);
      TwoThreeNode<T>* new_mid_node = new TwoThreeNode<T>(rootPtr->getValue());
      // creates new interior node from existing leaf node
      rootPtr->convertToInterior(rootPtr->getValue(), newEntry, new_left_node, new_mid_node, nullptr);
      rootPtr->setParentPtr(nullptr);
      new_mid_node->setParentPtr(rootPtr);
      new_left_node->setParentPtr(rootPtr);
    }
    else {
      // means that user tried to insert a number that already exists
      return false;
    }
  }
  // root is an interior node with 2 leaf children
  else if(rootPtr->isTwo() && rootPtr->getMidChildPtr()->getIsLeaf()) {
    // root interior node with no left subtree, therefore minMid and minRight have a value
    if(rootPtr->getRightChildPtr() != nullptr) {
      // new value is smaller than the minimum of the middle subtree
      if(newEntry < rootPtr->getMinMid()) {
        // we don't need to do anything fancy, just insert new node to empty left child pointer
        rootPtr->setLeftChildPtr(new_node);
      }
      // new value larger than minimum of the middle sub tree,
      // but smaller than the minimum of the right sub tree
      else if(newEntry < rootPtr->getMinRight()) {
        // need to replace minimum middle subtree and set left subtree to the value
        // that the minimum middle subtree had and set the minMid value as new value
        rootPtr->setLeftChildPtr(rootPtr->getMidChildPtr());
        rootPtr->setMinMid(newEntry);
        rootPtr->setMidChildPtr(new_node);
      }
      // new value is larger than the right subtree
      else if (newEntry > rootPtr->getMinRight()) {
        // set left child as mid child, set mid child as right child, set right child as new node
        // set min mid as new mid value, set min right as new right value
        TwoThreeNode<T>* temp_mid = rootPtr->getMidChildPtr();
        TwoThreeNode<T>* temp_right = rootPtr->getRightChildPtr();
        rootPtr->setMidChildPtr(nullptr);
        rootPtr->setRightChildPtr(nullptr);
        rootPtr->setLeftChildPtr(temp_mid);
        rootPtr->setMidChildPtr(temp_right);
        rootPtr->setRightChildPtr(new_node);
        rootPtr->setMinMid(temp_mid->getValue());
        rootPtr->setMinRight(temp_right->getValue());
      }
      // new value equals existing value
      else {
        return false;
      }
    }
    // insert when there is no right subtree
    else {
      // new value is smaller than the left subtree
      // need to replace leftchild with new node, replace mid with left, and set right as mid
      if(newEntry < (rootPtr->getLeftChildPtr())->getValue()) {
        TwoThreeNode<T>* temp_left = rootPtr->getLeftChildPtr();
        TwoThreeNode<T>* temp_mid = rootPtr->getMidChildPtr();
        rootPtr->setLeftChildPtr(nullptr);
        rootPtr->setMidChildPtr(nullptr);
        rootPtr->setLeftChildPtr(new_node);
        rootPtr->setMidChildPtr(temp_left);
        rootPtr->setRightChildPtr(temp_mid);
        rootPtr->setMinMid(temp_left->getValue());
        rootPtr->setMinRight(temp_mid->getValue());
      }
      // new value is larger than left but smaller than mid
      // replace mid with new node and set right as old mid
      // reset all min values
      else if (newEntry < rootPtr->getMinMid()) {
        TwoThreeNode<T>* temp_mid = rootPtr->getMidChildPtr();
        rootPtr->setMidChildPtr(nullptr);
        rootPtr->setMidChildPtr(new_node);
        rootPtr->setRightChildPtr(temp_mid);
        rootPtr->setMinMid(newEntry);
        rootPtr->setMinRight(temp_mid->getValue());
      }
      // new value larger than minimum of the middle sub tree,
      else if(newEntry > rootPtr->getMinMid()) {
        // we don't need to do anything fancy, just insert new node to empty right child pointer
        rootPtr->setRightChildPtr(new_node);
        rootPtr->setMinRight(newEntry);
      }
      // new value equals existing value
      else {
        return false;
      }
    }
  }
  // TODO: else if () { might need this if there is 2 interior nodes each with 3 children...

  // }
  else {
    // root has 3 children or interior nodes
    return (insertInorder(rootPtr, new_node, newEntry));
  }
	return true;
}
// 13 12 15 7 2 4 9 22
template<typename T>
TwoThreeNode<T>* TwoThreeTree<T>::insertInorder(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* newNodePtr, T newEntry) {
  if(subTreePtr == nullptr) {
    return(newNodePtr);
  }
  else if(subTreePtr->getIsLeaf()) {
    // TODO: Check what child it is (left, mid, or right) and split accordingly
    // TODO: What if values are inbetween children, not on the outside of
    // subTreePtr = right child
    if(subTreePtr->getParentPtr()->isTwo()) {
      // parent interior node with no left subtree, therefore minMid and minRight have a value
      if(subTreePtr->getParentPtr()->getRightChildPtr() != nullptr) {
        // new value is smaller than the minimum of the middle subtree
        if(newEntry < subTreePtr->getParentPtr()->getMinMid()) {
          // we don't need to do anything fancy, just insert new node to empty left child pointer
          subTreePtr->getParentPtr()->setLeftChildPtr(newNodePtr);
        }
        // new value larger than minimum of the middle sub tree,
        // but smaller than the minimum of the right sub tree
        else if(newEntry < subTreePtr->getParentPtr()->getMinRight()) {
          // need to replace minimum middle subtree and set left subtree to the value
          // that the minimum middle subtree had and set the minMid value as new value
          subTreePtr->getParentPtr()->setLeftChildPtr(subTreePtr->getParentPtr()->getMidChildPtr());
          subTreePtr->getParentPtr()->setMinMid(newEntry);
          subTreePtr->getParentPtr()->setMidChildPtr(newNodePtr);
        }
        // new value is larger than the right subtree
        else if (newEntry > subTreePtr->getParentPtr()->getMinRight()) {
          // set left child as mid child, set mid child as right child, set right child as new node
          // set min mid as new mid value, set min right as new right value
          TwoThreeNode<T>* temp_mid = subTreePtr->getParentPtr()->getMidChildPtr();
          TwoThreeNode<T>* temp_right = subTreePtr->getParentPtr()->getRightChildPtr();
          subTreePtr->getParentPtr()->setMidChildPtr(nullptr);
          subTreePtr->getParentPtr()->setRightChildPtr(nullptr);
          subTreePtr->getParentPtr()->setLeftChildPtr(temp_mid);
          subTreePtr->getParentPtr()->setMidChildPtr(temp_right);
          subTreePtr->getParentPtr()->setRightChildPtr(newNodePtr);
          subTreePtr->getParentPtr()->setMinMid(temp_mid->getValue());
          subTreePtr->getParentPtr()->setMinRight(temp_right->getValue());
        }
        // new value equals existing value
        else {
          return nullptr;
        }
      }
    }
    // subTreePtr is a 3 child parent
    else {
      if(subTreePtr->getValue() < newEntry) {
        // creates new leaf nodes, setting parent to the current node about to be turned into an interior node.
        newNodePtr->setParentPtr(subTreePtr);
        TwoThreeNode<T>* new_mid_node = new TwoThreeNode<T>(subTreePtr->getValue());
        // creates an interior node from existing leaf node
        TwoThreeNode<T>* old_left_leaf = new TwoThreeNode<T>(subTreePtr->getParentPtr()->getLeftChildPtr()->getValue());
        TwoThreeNode<T>* old_mid_leaf = new TwoThreeNode<T>(subTreePtr->getParentPtr()->getMidChildPtr()->getValue());
        subTreePtr->convertToInterior(subTreePtr->getValue(), newEntry, nullptr, new_mid_node, newNodePtr);
        new_mid_node->setParentPtr(subTreePtr);
        newNodePtr->setParentPtr(subTreePtr);
        // TODO: this was the issue. I passed in another node
        subTreePtr->getParentPtr()->getMidChildPtr()->convertToInterior(old_left_leaf->getValue(), old_mid_leaf->getValue(), nullptr, old_left_leaf, old_mid_leaf);
        subTreePtr->getParentPtr()->setMinMid(old_left_leaf->getValue());
        subTreePtr->getParentPtr()->setLeftChildPtr(nullptr);
        old_left_leaf->setParentPtr(subTreePtr->getParentPtr()->getMidChildPtr());
        old_mid_leaf->setParentPtr(subTreePtr->getParentPtr()->getMidChildPtr());
      }
      // subTreePtr = left child
      else if(subTreePtr->getValue() > newEntry) {
        // creates new leaf nodes
        newNodePtr->setParentPtr(subTreePtr);
        TwoThreeNode<T>* new_mid_node = new TwoThreeNode<T>(subTreePtr->getValue());
        TwoThreeNode<T>* old_right_leaf = new TwoThreeNode<T>(subTreePtr->getParentPtr()->getRightChildPtr()->getValue());
        TwoThreeNode<T>* old_mid_leaf = new TwoThreeNode<T>(subTreePtr->getParentPtr()->getMidChildPtr()->getValue());
        // creates new interior node
        subTreePtr->convertToInterior(subTreePtr->getValue(), newEntry, newNodePtr, new_mid_node, nullptr);

        // TODO: this was the issue. I passed in another node
        subTreePtr->getParentPtr()->getMidChildPtr()->convertToInterior(old_mid_leaf->getValue(),old_right_leaf->getValue(), nullptr, old_mid_leaf, old_right_leaf);
        subTreePtr->getParentPtr()->setMinRight(-1);
        subTreePtr->getParentPtr()->setRightChildPtr(nullptr);
        old_right_leaf->setParentPtr(subTreePtr->getParentPtr()->getMidChildPtr());
        old_mid_leaf->setParentPtr(subTreePtr->getParentPtr()->getMidChildPtr());
      }
      else {
        // means that user tried to insert a number that already exists
        // TODO: return?
      }
    }
  }

  // not at a leaf, continue searching
  else {
    newNodePtr->setParentPtr(subTreePtr);
    if(newEntry > subTreePtr->getMinRight()) {
      if(subTreePtr->getRightChildPtr() == nullptr) {
        subTreePtr->setRightChildPtr(newNodePtr);
      }
      else {
        return insertInorder(subTreePtr->getRightChildPtr(), newNodePtr, newEntry);
      }
    }
    // value is bigger than minMid and the right subtree isn't full, go right
    // else if(newEntry > subTreePtr->getMinMid() && subTreePtr->getRightChildPtr()->isTwo()) {
    //   return insertInorder(subTreePtr->getRightChildPtr(), newNodePtr, newEntry); // TODO: set breakpoint here
    // }
    // value is smaller than minMid but mid subtree isn't full, go mid
    else if(newEntry > subTreePtr->getMinMid() || (newEntry < subTreePtr->getMinMid() && subTreePtr->getMidChildPtr()->isTwo())) {
      return insertInorder(subTreePtr->getMidChildPtr(), newNodePtr, newEntry); // TODO: set breakpoint here
    }
    else if(newEntry < subTreePtr->getMinMid() && newEntry != findMin()) {
      if(subTreePtr->getLeftChildPtr() == nullptr) {
        subTreePtr->setLeftChildPtr(newNodePtr);
      }
      else {
        return insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr, newEntry);
      }
    }
  }
  return(subTreePtr);
}

template<typename T>
bool TwoThreeTree<T>::deleteMin_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr) {
  if(subTreePtr->getIsLeaf()) {
    if(parentPtr->isTwo() && parentPtr->getLeftChildPtr() == nullptr) {
      // sets interior node to a leaf node.
      TwoThreeNode<T>* temp_leaf = parentPtr->getRightChildPtr();
      std::cout << subTreePtr->getValue() << " has been deleted\n";
      parentPtr->setIsLeaf(true);
      parentPtr->setValue(temp_leaf->getValue());
      parentPtr->setMinMid(-1);
      parentPtr->setMinRight(-1);
      parentPtr->setLeftChildPtr(nullptr);
      parentPtr->setRightChildPtr(nullptr);
      parentPtr->setMidChildPtr(nullptr);
    }
    else if (parentPtr->isTwo() && parentPtr->getLeftChildPtr() != nullptr){
      // sets interior node to a leaf node.
      std::cout << subTreePtr->getValue() << " has been deleted\n";
      TwoThreeNode<T>* temp_leaf = parentPtr->getMidChildPtr();
      parentPtr->setIsLeaf(true);
      parentPtr->setValue(temp_leaf->getValue());
      parentPtr->setMinMid(-1);
      parentPtr->setMinRight(-1);
      parentPtr->setMidChildPtr(nullptr);
      parentPtr->setRightChildPtr(nullptr);
      parentPtr->setLeftChildPtr(nullptr);
    }
    // delete min if parent has 3 leaves
    else {
      std::cout << subTreePtr->getValue() << " has been deleted\n";
      // subTreePtr->setValue(-1);
      parentPtr->setLeftChildPtr(nullptr);
    }
  }
  return true;
}
template<typename T>
bool TwoThreeTree<T>::deleteMin() {
  if (rootPtr == nullptr) {
    return false;
  }
  else if(rootPtr->getIsLeaf()) {
    std::cout << rootPtr->getValue() << " has been deleted\n";
    delete rootPtr;
    rootPtr = nullptr;
    return true;
  }
  // if left child exists
  else if(rootPtr->getLeftChildPtr()!= nullptr) {
    return deleteMin_helper(rootPtr->getLeftChildPtr(), rootPtr);
  }
  // if left child doesn't exist
  else {
    return deleteMin_helper(rootPtr->getMidChildPtr(), rootPtr);
  }
}

template<typename T>
bool TwoThreeTree<T>::deleteMax_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr) {
  if(subTreePtr->getIsLeaf()) {
    if(parentPtr->isTwo() && parentPtr->getRightChildPtr() == nullptr) {
      // sets interior node to a leaf node.
      std::cout << subTreePtr->getValue() << " has been deleted\n";
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
      std::cout << subTreePtr->getValue() << " has been deleted\n";
      TwoThreeNode<T>* temp_leaf = parentPtr->getMidChildPtr();
      parentPtr->setIsLeaf(true);
      parentPtr->setValue(temp_leaf->getValue());
      parentPtr->setMinMid(-1);
      parentPtr->setMinRight(-1);
      parentPtr->setLeftChildPtr(nullptr);
      parentPtr->setRightChildPtr(nullptr);
      parentPtr->setMidChildPtr(nullptr);
    }
    // parent has 3 leaves
    else {
    // delete max if parent has 3 leaves
      std::cout << subTreePtr->getValue() << " has been deleted\n";
      // subTreePtr->setValue(-1);
      parentPtr->setRightChildPtr(nullptr);
    }
  }
  return true;
}

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
bool TwoThreeTree<T>::deleteMid(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr) {
  if(subTreePtr->getIsLeaf()) {
    if(parentPtr->isTwo() && parentPtr->getRightChildPtr() == nullptr) {
      // sets interior node to a leaf node.
	std::cout << "deleted from the if block\n";
      std::cout << subTreePtr->getValue() << " has been deleted\n";
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
	std::cout << "deleted from the else if block\n";
      std::cout << subTreePtr->getValue() << " has been deleted\n";
      TwoThreeNode<T>* temp_leaf = parentPtr->getRightChildPtr();
      parentPtr->setIsLeaf(true);
      parentPtr->setValue(temp_leaf->getValue());
      parentPtr->setMinMid(-1);
      parentPtr->setMinRight(-1);
      parentPtr->setLeftChildPtr(nullptr);
      parentPtr->setRightChildPtr(nullptr);
      parentPtr->setMidChildPtr(nullptr);
    }
    // parent has 3 leaves
    else {
    // delete middle leaf if parent has 3 leaves
    // set right leaf as middle leaf and minMid value as the rightMin values
    // set rightMin value to -1
      std::cout << subTreePtr->getValue() << " has been deleted in deletemid else part\n";
      TwoThreeNode<T>* temp_leaf = parentPtr->getLeftChildPtr();
      parentPtr->setMidChildPtr(nullptr);
      parentPtr->setLeftChildPtr(nullptr);
      parentPtr->setMidChildPtr(temp_leaf);
      parentPtr->setMinMid(temp_leaf->getValue());
    }
  }
  return true;
}
template<typename T>
bool TwoThreeTree<T>::deleteVal_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr, const T& value) {
  if (subTreePtr->getIsLeaf()) {
    if (subTreePtr->getValue() == value) {
      if (parentPtr->getLeftChildPtr() == subTreePtr) {
	std::cout << "delete min was called\n";
        return deleteMin_helper(subTreePtr, parentPtr);
      }
      else if (parentPtr->getMidChildPtr() == subTreePtr) {
	std::cout << "delete mid was called\n";
        return deleteMid(subTreePtr, parentPtr);
      }
      else {
	std::cout << "delete max was called\n";
        return deleteMax_helper(subTreePtr, parentPtr);
      }
    }
    else {
      return false;
    }
  }
  // value is smaller than min of mid subtree, go down left subtree
  else if(value < subTreePtr->getMinMid()) {
    if (subTreePtr->getLeftChildPtr() != nullptr) {
      return deleteVal_helper(subTreePtr->getLeftChildPtr(), subTreePtr, value);
    }
    // there is no left subtree, value doesn't exist
    else {
      return false;
    }
  }
  // value is smaller than min of right subtree, go down mid subtree
  else if (value < subTreePtr->getMinRight()) {
    return deleteVal_helper(subTreePtr->getMidChildPtr(), subTreePtr, value);
  }
  // value is greater than min of right subtree, go down right subtree
  else {
    if (subTreePtr->getRightChildPtr() != nullptr) {
      return deleteVal_helper(subTreePtr->getRightChildPtr(), subTreePtr, value);
    }
    // there is no right subtree, value doesn't exist
    else {
      return false;
    }
  }
}
template<typename T>
bool TwoThreeTree<T>::deleteVal(const T& value) {
  if(rootPtr->getIsLeaf()) {
    if(rootPtr->getValue() == value) {
      return deleteMax();
    }
    else {
      return false;
    }
  }
  else {
    // value is smaller than min of mid subtree, go down left subtree
    if(value < rootPtr->getMinMid()) {
      if (rootPtr->getLeftChildPtr() != nullptr) {
        return deleteVal_helper(rootPtr->getLeftChildPtr(), rootPtr, value);
      }
      // there is no left subtree, value doesn't exist
      else {
        return false;
      }
    }
    // value is smaller than min of right subtree, go down mid subtree
    else if (value < rootPtr->getMinRight() || value == rootPtr->getMinMid()) {
      return deleteVal_helper(rootPtr->getMidChildPtr(), rootPtr, value);
    }
    // value is greater than min of right subtree, go down right subtree
    else {
      if (rootPtr->getRightChildPtr() != nullptr) {
        return deleteVal_helper(rootPtr->getRightChildPtr(), rootPtr, value);
      }
      // there is no right subtree, value doesn't exist
      else {
        return false;
      }
    }
  }
}

// TODO: Not sure if I need this function
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
  // tree is empty
  if(rootPtr == nullptr) {
    return false;
  }
  // root is only value
  else if (rootPtr->getIsLeaf()) {
    std::cout << rootPtr->getValue() << " is the min value\n";
    return true;
  }
  // root has a left child
  else if (rootPtr->getLeftChildPtr()){
    return findMinHelper(rootPtr->getLeftChildPtr());
  }
  // root does not have a left child, therefore has a middle child
  else {
    return findMinHelper(rootPtr->getMidChildPtr());
  }
}
template<typename T>
bool TwoThreeTree<T>::findMinHelper(TwoThreeNode<T>* subTreePtr) {
  while (subTreePtr->getLeftChildPtr() != nullptr) {
    subTreePtr = subTreePtr->getLeftChildPtr();
  }
  while (subTreePtr->getMidChildPtr() != nullptr) {
    subTreePtr = subTreePtr->getMidChildPtr();
  }
  std::cout << subTreePtr->getValue() << " is the min value\n";
  return true;
}

template<typename T>
bool TwoThreeTree<T>::findMax() {
  if(rootPtr == nullptr) {
    return false;
  }
  else if (rootPtr->getIsLeaf()) {
    std::cout << rootPtr->getValue() << " is the max value\n";
    return true;
  }
  // root has right child
  else if (rootPtr->getRightChildPtr()){
    return findMaxHelper(rootPtr->getRightChildPtr());
  }
  // root does not have right child therefore has mid child
  else {
    return findMaxHelper(rootPtr->getMidChildPtr());
  }
}
template<typename T>
bool TwoThreeTree<T>::findMaxHelper(TwoThreeNode<T>* subTreePtr) {
  while (subTreePtr->getRightChildPtr() != nullptr) {
    subTreePtr = subTreePtr->getRightChildPtr();
  }
  while (subTreePtr->getMidChildPtr() != nullptr) {
    subTreePtr = subTreePtr->getMidChildPtr();
  }
  std::cout << subTreePtr->getValue() << " is the max value\n";
  return true;
}

template<typename T>
bool TwoThreeTree<T>::find(T value) {
  if(rootPtr == nullptr) {
    return false;
  }
  else if(rootPtr->getIsLeaf()) {
    if(rootPtr->getValue() == value) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    // value is smaller than min of mid subtree, go down left subtree
    if(value < rootPtr->getMinMid()) {
      if (rootPtr->getLeftChildPtr() != nullptr) {
        return findHelper(rootPtr->getLeftChildPtr(), value);
      }
      // there is no left subtree, value doesn't exist
      else {
        return false;
      }
    }
    // value is smaller than min of right subtree, go down mid subtree
    else if (value < rootPtr->getMinRight() || value == rootPtr->getMinMid()) {
      return findHelper(rootPtr->getMidChildPtr(), value);
    }
    // value is greater than min of right subtree, go down right subtree
    else {
      if (rootPtr->getRightChildPtr() != nullptr) {
        return findHelper(rootPtr->getRightChildPtr(), value);
      }
      // there is no right subtree, value doesn't exist
      else {
        return false;
      }
    }
  }
}

template<typename T>
bool TwoThreeTree<T>::findHelper(TwoThreeNode<T>* subTreePtr, T value) {
  if (subTreePtr->getIsLeaf()) {
    if (subTreePtr->getValue() == value) {
      return true;
    }
    else {
      return false;
    }
  }
  // value is smaller than min of mid subtree, go down left subtree
  else if(value < subTreePtr->getMinMid()) {
    if (subTreePtr->getLeftChildPtr() != nullptr) {
      return findHelper(subTreePtr->getLeftChildPtr(), value);
    }
    // there is no left subtree, value doesn't exist
    else {
      return false;
    }
  }
  // value is smaller than min of right subtree, go down mid subtree
  else if (value < subTreePtr->getMinRight()) {
    return findHelper(subTreePtr->getMidChildPtr(), value);
  }
  // value is greater than min of right subtree, go down right subtree
  else {
    if (subTreePtr->getRightChildPtr() != nullptr) {
      return findHelper(subTreePtr->getRightChildPtr(), value);
    }
    // there is no right subtree, value doesn't exist
    else {
      return false;
    }
  }
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
      // std::cout << "min mid: " << subTreePtr->getMinMid() << " min right: " << subTreePtr->getMinRight() << "\n";
      // std::cout << "go left\n";
      levelHelper(subTreePtr->getLeftChildPtr());
    }
    if(subTreePtr->getMidChildPtr() != nullptr) {
      // std::cout << "min mid: " << subTreePtr->getMinMid() << " min right: " << subTreePtr->getMinRight() << "\n";
      // std::cout << "go mid\n";
      levelHelper(subTreePtr->getMidChildPtr());
    }
    if(subTreePtr->getRightChildPtr() != nullptr) {
      // std::cout << "min mid: " << subTreePtr->getMinMid() << " min right: " << subTreePtr->getMinRight() << "\n";
      // std::cout << "go right\n";
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
void TwoThreeTree<T>::destroyTree(TwoThreeNode<T>* subTreePtr) {
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
