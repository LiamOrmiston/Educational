/*
---------------------------
Author: Liam Ormiston
Date late updated: 10-4-16
Project: Lab 04 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Elevator Action
---------------------------
*/
#include "Queue.h"
#include "Node.h"

template <typename T>
Queue<T>::Queue()
{
  m_front = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{

}

template <typename T>
bool Queue<T>::isEmpty() const
{
  if(m_length == 0)
  {
    return (0);
  }
  else
  {
    return (1);
  }
}

template <typename T>
void Queue<T>::enqueue(const T value)
{
  if(!isEmpty())
  {
    m_front = new Node<T>();
    m_front -> setValue(value);
    m_back = m_front;
    m_length ++;
  }
  else
  {
    Node<T>* last = new Node<T>();
    last -> setValue(value);
    last -> setPrev(m_back);
    m_back -> setNext(last);
    m_back = last;
    m_length ++;
  }
}

template <typename T>
void Queue<T>::dequeue() throw(PreconditionViolationException)
{
  if (isEmpty() == 0)
  {
    throw (PreconditionViolationException ("Dequeue attempted on a empty queue"));
  }
  else if(m_length==0)
  {
    m_back = nullptr;
  }
  else
  {
    Node<T>* oldFront = m_front;
    Node<T>* newFront = m_front->getNext();
    m_front = newFront;
    delete oldFront;
    m_length--;
  }
}
    //assumes the queue is not empty
    //front of the front is removed
    //throws PreconditionViolationException if attempted on an empty queue. Does not return a value in this case.

template <typename T>
T Queue<T> :: peekFront() const throw(PreconditionViolationException)
{
  if(isEmpty() == 0)
  {
     throw PreconditionViolationException("Queue is empty");
  }
  else
  {

    std::string x = m_front->getValue();
    return (x);
  }

}
    //assumes the queue is not empty
    //returns the value at the front of the stack
    //throws a PreconditionViolationException if attempted on an empty queue. Does not return a value in this case.
