//  Subsetted from:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file BinarySearchTree.cpp */
#include <iostream>

#include "BinarySearchTree.h"
#include <fstream>

// PRIVATE HELPER METHODS - IMPLEMENT THESE

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
  //recurse left subtree
  if(subTreePtr->getLeftChildPtr() != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
  }

  //recurse right subtree
  if(subTreePtr->getRightChildPtr() != nullptr)
  {
    destroyTree(subTreePtr->getRightChildPtr());
  }

  //deletes node
  delete subTreePtr;
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType,KeyType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                                                BinaryNode<ItemType>* newNodePtr)
{
  if(subTreePtr == nullptr)
  {
    return(newNodePtr);
  }
  else if(subTreePtr->getItem() > newNodePtr->getItem())
  {
    BinaryNode<ItemType>* temp = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
    subTreePtr -> setLeftChildPtr(temp);
  }
  else
  {
    BinaryNode<ItemType>* temp = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
    subTreePtr -> setRightChildPtr(temp);
  }

  return(subTreePtr);
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::findNode(
				BinaryNode<ItemType>* subTreePtr, const KeyType& target) const
{
  if(subTreePtr == nullptr)
  {
  return (nullptr);
  }
  else if (subTreePtr->getItem().getAName() > target)
  {
    return (findNode(subTreePtr->getLeftChildPtr(), target));
  }
  else if (subTreePtr->getItem().getAName() < target)
  {
    return(findNode(subTreePtr->getRightChildPtr(), target));
  }
  else
  {
    return(subTreePtr);
  }
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree()
{
  rootPtr = nullptr;
}

template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::add(const ItemType& newEntry)
{
  BinaryNode<ItemType>* new_node = new BinaryNode<ItemType>(newEntry);

  rootPtr = (insertInorder(rootPtr, new_node));

	return true;
}


template<typename ItemType, typename KeyType>
ItemType BinarySearchTree<ItemType, KeyType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{
  BinaryNode<ItemType>* temp = findNode(rootPtr, aKey);

    if(temp == nullptr)
    {
      throw(NotFoundException("That pokemon was not found!"));
    }
    else
    {
      return(temp->getItem());
    }
}


//////////////////////////////////////////////////////////////
//      Public Traversals Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////


//Pre, In, Post methods for save function
template<typename ItemType, typename KeyType>
std::string BinarySearchTree<ItemType, KeyType>::preHelper(BinaryNode<ItemType>* subTreePtr)
{
  std::string a = subTreePtr->getItem().getAName()+", "+subTreePtr->getItem().getDex()+", "+subTreePtr->getItem().getJName();
  o_file << a;

  if(subTreePtr->getLeftChildPtr() != nullptr)
  {
    preHelper(subTreePtr->getLeftChildPtr());
  }
  if(subTreePtr->getRightChildPtr() != nullptr)
  {
    preHelper(subTreePtr->getRightChildPtr());
  }
  return(a);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::pre(std::string fileName)
{
  o_file.open(fileName);
  preHelper(rootPtr);
  o_file.close();
}
template<typename ItemType, typename KeyType>
std::string BinarySearchTree<ItemType, KeyType>::inHelper(BinaryNode<ItemType>* subTreePtr)
{
  if(subTreePtr->getLeftChildPtr() != nullptr)
  {
    inHelper(subTreePtr->getLeftChildPtr());
  }

  std::string a = subTreePtr->getItem().getAName()+", "+subTreePtr->getItem().getDex()+", "+subTreePtr->getItem().getJName()+"\n";
  o_file << a;

  if(subTreePtr->getRightChildPtr() != nullptr)
  {
    inHelper(subTreePtr->getRightChildPtr());
  }
  return(a);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::in(std::string fileName)
{
  o_file.open(fileName);
  inHelper(rootPtr);
  o_file.close();
}

template<typename ItemType, typename KeyType>
std::string BinarySearchTree<ItemType, KeyType>::postHelper(BinaryNode<ItemType>* subTreePtr)
{
  if(subTreePtr->getLeftChildPtr() != nullptr)
  {
    postHelper(subTreePtr->getLeftChildPtr());
  }
  if(subTreePtr->getRightChildPtr() != nullptr)
  {
    postHelper(subTreePtr->getRightChildPtr());
  }

  std::string a = subTreePtr->getItem().getAName()+", "+subTreePtr->getItem().getDex()+", "+subTreePtr->getItem().getJName();
  o_file << a;
  return(a);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::post(std::string fileName)
{
  o_file.open(fileName);
  postHelper(rootPtr);
  o_file.close();
}




//Print Method for Test
template<typename ItemType, typename KeyType>
std::string BinarySearchTree<ItemType, KeyType>::print_inHelper(BinaryNode<ItemType>* subTreePtr)
{
  if(subTreePtr->getLeftChildPtr() != nullptr)
  {
    print_inHelper(subTreePtr->getLeftChildPtr());
  }

  std::string a = subTreePtr->getItem().getAName()+", "+subTreePtr->getItem().getDex()+", "+subTreePtr->getItem().getJName();
  std::cout << a <<std::endl;

  if(subTreePtr->getRightChildPtr() != nullptr)
  {
    print_inHelper(subTreePtr->getRightChildPtr());
  }
  return(a);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::print_in()
{
  print_inHelper(rootPtr);
}
