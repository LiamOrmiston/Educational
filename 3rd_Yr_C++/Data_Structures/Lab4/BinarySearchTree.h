#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"

template <typename T>
class BinarySearchTree {
public:
  // Constructor and Destructor
  BinarySearchTree();
  virtual ~BinarySearchTree();

  // insert and delete
  bool add(const T& newEntry);
  bool deleteMin();
  bool deleteMin_helper(BinaryNode<T>* subTreePtr, BinaryNode<T>* parentPtr);
  bool deleteMax();
  bool deleteMax_helper(BinaryNode<T>* subTreePtr, BinaryNode<T>* parentPtr);
  bool deleteVal(const T& value);
  bool deleteVal_helper(BinaryNode<T>* subTreePtr, BinaryNode<T>* parentPtr, const T& value);
  T rightMin(BinaryNode<T>* subTreePtr);



  // find functions
  bool findMin();
  bool findMinHelper(BinaryNode<T>* subTreePtr);
  bool findMax();
  bool findMaxHelper(BinaryNode<T>* subTreePtr);

  void getEntry(const T& aKey);

   // Traversals
  void pre();
  void preHelper(BinaryNode<T>* subTreePtr);
  void in();
  void inHelper(BinaryNode<T>* subTreePtr);
  void post();
  void postHelper(BinaryNode<T>* subTreePtr);

private:
   BinaryNode<T>* rootPtr;

   // Recursively deletes all nodes from the tree.
   void destroyTree(BinaryNode<T>* subTreePtr);

   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   BinaryNode<T>* insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target) const;
};

#include "BinarySearchTree.hpp"
#endif
