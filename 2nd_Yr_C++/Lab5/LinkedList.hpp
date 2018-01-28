/*
---------------------------
Author: Liam Ormiston
Date late updated: 10-13-16
Project: Lab 05 - EECS 268
Instructor: Dr. Gibbons
TA: Prasanth Vivekanandan
School: University of Kansas
Title: Recursive exercises
---------------------------
*/
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Node.h"

//constructor
template <typename T>
LinkedList<T>::LinkedList()
{
  m_front = nullptr;
  m_length = 0;
}

//destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
  Node<T>* current = m_front;
  while( current != nullptr )
  {
    Node<T>* next = current -> getNext();
    delete current;
    current = next;
  }
  m_front = nullptr;
}

//checks to see if the node is empty
template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if(m_front == nullptr)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

//adds node to front of the list
template <typename T>
void LinkedList<T>::addFront(T value)
{
  if(isEmpty())
  {
    m_front = new Node<T>();
    m_front -> setValue(value);
    m_length++;
  }
  else
  {
    Node<T>* temp;
    temp = new Node<T>();
    temp -> setValue(value);
    temp -> setNext(m_front);
    m_front = temp;
    m_length ++;
  }
}

//tracks to the end of the list then adds node to the back
template <typename T>
void LinkedList<T>::addBack(T value)
{
  if(isEmpty())
  {
    addFront(value);
  }
  else
  {
    Node<T>* temp = nullptr;
    Node<T>* last = nullptr;
    last = m_front;
    while(last -> getNext() != nullptr)
    {
      last = last -> getNext();
    }
    temp = new Node<T>;
    temp -> setValue(value);
    last -> setNext(temp);
    temp = nullptr;
    delete temp;
    m_length ++;
  }
}

//tracks the list to the end keeping track how long the list is
template <typename T>
int LinkedList<T>::getLength() const
{
  return m_length;
}

//returns what a specific nodes contains at a certain given position
template <typename T>
T LinkedList<T>::getEntry(int position) const
{
  Node<T>* temp = nullptr;
  temp = m_front;
  for(int i = 1; i != position; i++)
  {
    temp = temp -> getNext();
  }
  return (temp -> getValue());
}

//moves the flip method down the linked list
template <typename T>
void LinkedList<T>::reverseList()
{
  Node<T>* temp = m_front;
  if(temp != nullptr && temp -> getNext() != nullptr)
  {
    flip(temp);
  }
  temp -> setNext(nullptr);
}

//flips the pointer of the node
template <typename T>
void LinkedList<T>::flip (Node<T>* temp)
{
  if (temp->getNext() != nullptr)
  {
    Node<T>* next = temp->getNext();
    flip(next);
    next->setNext(temp);
  }
  else
  {
    m_front = temp;
  }
}
