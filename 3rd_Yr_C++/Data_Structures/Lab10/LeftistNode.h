#ifndef LEFTIST_NODE
#define LEFTIST_NODE

template <typename T>
class LeftistNode {
public:
   LeftistNode();
   ~LeftistNode();
   LeftistNode(const T& value);
   LeftistNode(const T& value, LeftistNode<T>* leftPtr, LeftistNode<T>* rightPtr);
   bool isLeaf() const;

   // Getters
   T getValue() const;
   T getRank() const;
   LeftistNode<T>* getLeftChildPtr() const;
   LeftistNode<T>* getRightChildPtr() const;

   // Setters
   void setValue(const T& value);
   void setRank(const T& rank);
   void setLeftChildPtr(LeftistNode<T>* leftPtr);
   void setRightChildPtr(LeftistNode<T>* rightPtr);

private:
  T value;           // Data portion
  T rank;            // Data portion
  LeftistNode<T>* leftChildPtr;   // Pointer to left child
  LeftistNode<T>* rightChildPtr;  // Pointer to right child
};
#include "LeftistNode.hpp"
#endif
