//  Subsetted from:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"
#include "Pokemon.h"
#include "NotFoundException.h"

template<typename ItemType, typename KeyType>
class BinarySearchTree
{
private:
   BinaryNode<ItemType>* rootPtr;

   // Recursively deletes all nodes from the tree.
   void destroyTree(BinaryNode<ItemType>* subTreePtr);

   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const KeyType& target) const;

   std::ofstream o_file;

public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   virtual ~BinarySearchTree();

   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool add(const ItemType& newEntry);
   ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);
   //bool contains(const KeyType& aKey) const;

   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------

  // void inorderTraverse(void visit(ItemType&)) const;
  void pre(std::string fileName);
  std::string preHelper(BinaryNode<ItemType>* subTreePtr);
  void in(std::string fileName);
  std::string inHelper(BinaryNode<ItemType>* subTreePtr);
  void post(std::string fileName);
  std::string postHelper(BinaryNode<ItemType>* subTreePtr);

  void print_in();
  std::string print_inHelper(BinaryNode<ItemType>* subTreePtr);



}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
