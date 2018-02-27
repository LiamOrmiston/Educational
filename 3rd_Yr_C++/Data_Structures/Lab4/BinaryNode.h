#ifndef _BINARY_NODE
#define _BINARY_NODE

template <typename T>
class BinaryNode {
public:
   BinaryNode();
   ~BinaryNode();
   BinaryNode(const T& value);
   BinaryNode(const T& value, BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr);
   bool isLeaf() const;

   // Getters
   T getValue() const;
   BinaryNode<T>* getLeftChildPtr() const;
   BinaryNode<T>* getRightChildPtr() const;

   // Setters
   void setValue(const T& value);
   void setLeftChildPtr(BinaryNode<T>* leftPtr);
   void setRightChildPtr(BinaryNode<T>* rightPtr);

private:
  T value;           // Data portion
  BinaryNode<T>* leftChildPtr;   // Pointer to left child
  BinaryNode<T>* rightChildPtr;  // Pointer to right child
};
#include "BinaryNode.hpp"
#endif
