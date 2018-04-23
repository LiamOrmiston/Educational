#ifndef SKEW_NODE
#define SKEW_NODE

template <typename T>
class SkewNode {
public:
   SkewNode();
   ~SkewNode();
   SkewNode(const T& value);
   SkewNode(const T& value, SkewNode<T>* leftPtr, SkewNode<T>* rightPtr);

   // Getters
   T getValue() const;
   SkewNode<T>* getLeftChildPtr() const;
   SkewNode<T>* getRightChildPtr() const;

   // Setters
   void setValue(const T& value);
   void setLeftChildPtr(SkewNode<T>* leftPtr);
   void setRightChildPtr(SkewNode<T>* rightPtr);

private:
  T value;                     // Data portion
  SkewNode<T>* leftChildPtr;   // Pointer to left child
  SkewNode<T>* rightChildPtr;  // Pointer to right child
};
#include "SkewNode.hpp"
#endif
