#include "PriorityQueue.h"
#include "Heap.h"

//constructor create new heap
template <typename T>
PriorityQueue<T>::PriorityQueue(int initialSize)
{
  theHeap = new Heap<T>(initialSize);
}

//copy constructor creates new heap the points to the previous heap
template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& pq)
{
  theHeap = new Heap<T>(*pq.theHeap);
}
//destructor
template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
  theHeap -> ~Heap();
}

//adds new entry by calling the add heap
template <typename T>
void PriorityQueue<T>::enqueue(T newEntry)
{
  theHeap -> add(newEntry);
}

//removes first entry by calling the remove heap
template <typename T>
void PriorityQueue<T>::dequeue() throw (EmptyPriorityQueue)
{
  try
  {
    theHeap -> remove();
  }
  catch (EmptyHeap h)
  {
    throw(EmptyPriorityQueue("The priority queue is empty!"));
  }

}

//checks to see if the queue is empty by calling the heap isEmpty
template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
  if(theHeap->isEmpty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

//returns the first item in queue by calling the heap peak function
template <typename T>
T PriorityQueue<T>::peekFront() const throw (EmptyPriorityQueue)
{
  if(!isEmpty())
  {
    return(theHeap -> peekTop());
  }
  else
  {
    throw(EmptyPriorityQueue("The priority queue is empty!"));
  }
}
