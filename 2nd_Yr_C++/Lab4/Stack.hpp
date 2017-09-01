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
#include "Stack.h"
#include "Node.h"
#include "PreconditionViolationException.h"

template <typename T>
Stack<T>::Stack()
{
  m_top = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{

}

//checks to see if Stack is empty by looking to see if the top node is pointing
//at nullptr
template <typename T>
bool Stack<T>::isEmpty() const
{
  if (m_size == 0)
  {
    return (true);
  }
  else
  {
    return (false);
  }
}

template <typename T>
void Stack<T>::push(const T newEntry) throw(PreconditionViolationException)
{
  if(isEmpty())
  {
    m_top = new Node<T>();
    m_top -> setValue(newEntry);
    m_size ++;
  }
  else if(m_size == 7)
  {
    throw PreconditionViolationException("Exception: Push attempted on full elevator");
  }
  else
  {
    Node<T>* first = new Node<T>();
    first -> setValue(newEntry);
    first -> setNext(m_top);
    m_top = first;
    m_size ++;
  }
}

template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
  if(isEmpty())
  {
    throw PreconditionViolationException("Exception: Pop attempted on empty stack");
  }
  else
  {
    Node<T>* oldFront = m_top;
    Node<T>* newFront = m_top->getNext();
    m_top = newFront;
    delete oldFront;
    m_size--;
  }
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
  if(isEmpty())
  {
     throw PreconditionViolationException("Stack is empty");
  }
  else
  {
    std::string x = m_top->getValue();
    return (x);
  }
}
