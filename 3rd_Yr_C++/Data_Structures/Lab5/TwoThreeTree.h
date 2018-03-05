#ifndef _TWO_THREE_TREE
#define _TWO_THREE_TREE

#include "TwoThreeNode.h"

template <typename T>
class TwoThreeTree {
public:
  // Constructor and Destructor
  TwoThreeTree();
  virtual ~TwoThreeTree();

  // insert and delete
  bool insert(const T& newEntry);
  bool deleteMin();
  bool deleteMin_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr);
  bool deleteMax();
  bool deleteMax_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr);
  bool deleteVal(const T& value);
  bool deleteVal_helper(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* parentPtr, const T& value);
  T rightMin(TwoThreeNode<T>* subTreePtr);



  // find functions
  bool findMin();
  bool findMinHelper(TwoThreeNode<T>* subTreePtr);
  bool findMax();
  bool findMaxHelper(TwoThreeNode<T>* subTreePtr);
  bool find(T value);
  bool findHelper(TwoThreeNode<T>* subTreePtr, T value);
  void getEntry(const T& aKey);

   // Traversals
  void level();
  void levelHelper(TwoThreeNode<T>* subTreePtr);

private:
   TwoThreeNode<T>* rootPtr;

   // Recursively deletes all nodes from the tree.
   void destroyTree(TwoThreeNode<T>* subTreePtr);

   // Recursively finds where the given node should be placed and
   // inserts it as a leaf at that point.
   TwoThreeNode<T>* insertInorder(TwoThreeNode<T>* subTreePtr, TwoThreeNode<T>* newNodePtr);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   TwoThreeNode<T>* findNode(TwoThreeNode<T>* treePtr, const T& target) const;
};

#include "TwoThreeTree.hpp"
#endif
