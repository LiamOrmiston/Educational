#include "Heap.h"
#include <string>
#include <iostream>
#include <ostream>

//constructor
template <typename T>
Heap<T>::Heap(int initialSize)
{
  sizeOfArray = initialSize ;
  theCompleteBinaryTree = new T[sizeOfArray];
  numItemsInHeap = 0;
}
//the copy constructor
template <typename T>
Heap<T>::Heap(const Heap<T>& heap)
{
  sizeOfArray = heap.sizeOfArray;
  numItemsInHeap = heap.numItemsInHeap;
  theCompleteBinaryTree = new T[sizeOfArray];

  for(int i = 0; i < heap.sizeOfArray; i++)
  {
    theCompleteBinaryTree[i] = heap.theCompleteBinaryTree[i];
  }
}

//destructor
template <typename T>
Heap<T>::~Heap()
{
  delete [] theCompleteBinaryTree;
  theCompleteBinaryTree = nullptr;
}
//add method used to add new patients into the max heap
template <typename T>
void Heap<T>::add(T& newItem)
{
//checks to see if the array is empty
  if(isEmpty())
  {
//adds new item to the first position
    theCompleteBinaryTree[0] = newItem;
  }
  else
  {
//if the items exceed the space of the array then a copy of the new array must be made with twice the size
//of the old array
    if(numItemsInHeap == sizeOfArray)
    {
      //copy array
      T* newArray = new T[sizeOfArray*2];
      for(int i = 0; i < sizeOfArray; i++)
      {
        newArray [i] = theCompleteBinaryTree[i];
      }
//increases size by x2
      sizeOfArray = sizeOfArray * 2;

//deletes old array and overloads the array to look at the new array
      delete [] theCompleteBinaryTree;
      theCompleteBinaryTree = newArray;
    }


//adds the new item to the array
      theCompleteBinaryTree[numItemsInHeap] = newItem;

      int newItemPos = numItemsInHeap;
      bool inPos = false;

//sorts the new item within the array
      while (newItemPos >= 0 && !(inPos))
      {
        int parentPos = ((newItemPos - 1)/2);

//checks to see if it's in the correct position
        if(theCompleteBinaryTree[newItemPos] <= theCompleteBinaryTree[parentPos])
        {
          inPos = true;
        }
//if it isn't then it will swap parent with child
        else
        {
          T* temp = new T();
          *temp = theCompleteBinaryTree[parentPos];
          theCompleteBinaryTree[parentPos] = theCompleteBinaryTree [newItemPos];
          theCompleteBinaryTree[newItemPos] = *temp;
          newItemPos = parentPos;
          delete temp;
        }
      }
  }
//once added then increases number of items in Heap
  numItemsInHeap++;

}

//checks to see if heap is empty by checking the value of the number of items in the heap
template <typename T>
bool Heap<T>::isEmpty() const
{
  if (numItemsInHeap == 0)
  {
    return (true);
  }
  else
  {
    return (false);
  }
}


//recursively reorders the heap.
//**Only used if the root is removed.
template <typename T>
void Heap<T>::rebuildHeap(int newPatPos)
{
//defines the left and right child position
  int leftChildPos = 2 * newPatPos + 1;
  int rightChildPos = leftChildPos + 1;
  int largerChildPos = rightChildPos;
  if(leftChildPos < numItemsInHeap)
  {
//checks to make sure the larger number is in the left child
    if ((largerChildPos >= numItemsInHeap) || theCompleteBinaryTree[leftChildPos] > theCompleteBinaryTree[rightChildPos])
    {
      largerChildPos = leftChildPos;
    }
//swaps the root with the larger number and recursively calls itself again until the largest number is the root
    if (theCompleteBinaryTree[largerChildPos] > theCompleteBinaryTree[newPatPos])
    {
      T* temp = new T();
      *temp = theCompleteBinaryTree[newPatPos];
      theCompleteBinaryTree[newPatPos] = theCompleteBinaryTree [largerChildPos];
      theCompleteBinaryTree[largerChildPos] = *temp;
      delete temp;
      rebuildHeap(largerChildPos);
    }
  }
}

//remove function
template <typename T>
void Heap<T>::remove() throw (EmptyHeap)
{
//swaps the first item with the last item and then decreases the number of items in the array
//this will insure that the removed item will never be accesssed.
  if(!isEmpty())
  {
    theCompleteBinaryTree[0] = theCompleteBinaryTree[numItemsInHeap - 1];
    numItemsInHeap --;
    rebuildHeap(0);
  }
//if heap is empty then it will throw empty heap exception
  else
  {
    throw(EmptyHeap("The heap is empty!"));
  }
}

//peek top will return the first item in the array
template <typename T>
T Heap<T>::peekTop() const throw (EmptyHeap)
{
  if(!isEmpty())
  {
    return(theCompleteBinaryTree[0]);
  }
  else
  {
    throw(EmptyHeap("The heap is empty!"));
  }
}
