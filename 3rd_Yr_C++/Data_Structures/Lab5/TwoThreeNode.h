#ifndef _TWO_THREE_NODE
#define _TWO_THREE_NODE

template <typename T>
class TwoThreeNode {
public:
   TwoThreeNode();
   ~TwoThreeNode();
   TwoThreeNode(const T& value);
   // TwoThreeNode(const T& value, TwoThreeNode<T>* leftPtr, TwoThreeNode<T>* midPtr, TwoThreeNode<T>* rightPtr);

   // Getters
   T getValue() const;
   T getMinMid() const;
   T getMinRight() const;
   bool getIsLeaf() const;
   TwoThreeNode<T>* getLeftChildPtr() const;
   TwoThreeNode<T>* getMidChildPtr() const;
   TwoThreeNode<T>* getRightChildPtr() const;
   TwoThreeNode<T>* getParentPtr() const;

   // Setters
   void setValue(const T& value);
   void setMinMid(const T& value);
   void setMinRight(const T& value);
   void setIsLeaf(const bool value);
   void setLeftChildPtr(TwoThreeNode<T>* leftPtr);
   void setMidChildPtr(TwoThreeNode<T>* midPtr);
   void setRightChildPtr(TwoThreeNode<T>* rightPtr);
   void setParentPtr(TwoThreeNode<T>* aParentPtr);

private:
  bool isLeaf;                     // Tag for either interior node or leaf node
  T value;                         // Value of the leaf
  T minMid;                        // Min value of mid child
  T minRight;                      // Min value of right child
  TwoThreeNode<T>* leftChildPtr;   // Pointer to left child
  TwoThreeNode<T>* midChildPtr;    // Pointer to mid child
  TwoThreeNode<T>* rightChildPtr;  // Pointer to right child
  TwoThreeNode<T>* parentPtr;      // Pointer to parent
};
#include "TwoThreeNode.hpp"
#endif

/* TODO: create interior node constructor
*/
