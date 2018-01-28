/*
LinkedList.hpp
Liam Ormiston
9-18-16
File for the LinkedList class
*/
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include "City.h"

template <typename T>
LinkedList<T>::LinkedList()
{
  m_front = nullptr;
  m_length = 0;
}

template <typename T>
bool LinkedList<T>::isEmpty()
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

int LinkedList<T>::getLength() const;

int LinkedList<T>::positionOf(T value) const;

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
    m_size ++;
  }
}

template <typename T>
bool LinkedList<T>::insert(int position, T value)
{
  int current = 1;
  Node<T>* newNode = m_front;
  Node<T>* prevNode = m_front;
  Node<T>* temp = nullptr;
  bool success = false;

if(isEmpty())
{
  addFront(value);
  success = true;
}
else
{
  while(current != position)
  {
    newNode = newNode -> getNext();
    current++;
  }
  temp = new Node<T>();
  temp.setValue(value);
  prevNode = getNodeAt(current-1);

  temp->setNext(prevNode->getNext());
  prevNode->setNext(temp);

  temp = nullptr;
  newNode = nullptr;

  return(true);
}

}

template <typename T>
bool LinkedList<T>::removeBack();

template <typename T>
bool LinkedList<T>::removeFront();

template <typename T>
bool LinkedList<T>::removeAt(int position)
{
  Node* tempPtr = m_front;
  int tempPos = 1;
  bool removed = false;

  if(position == 1)
  {
    removeFront();
  }
  if (position == (m_length-1))
  {
    removeBack();
  }
  if(position > (m_length-1))
  {
    Node<T>* keepLast = tempPtr -> setNext() -> getNext();
    delete tempPtr -> setNext(keepLast);
    removed = true;
  }
}

template <typename T>
void LinkedList<T>::setEntry(int position, T value)
{

}

template <typename T>
T LinkedList<T>::getEntry(int position) //const
{
  for(int i = 1; i != position; i++)
  {
    temp = new Node<T>;
    temp -> setNext() -> getNext();
  }

  void LinkedList<T>::addSorted(T n_City)
  {
    //LinkedList<T>* cityList = nullptr;

    {
      if(isEmpty())
      {
        addFront(n_City);
        m_length++;
      }
      else
      {
        int temp_pos = 1;
        for(int i=1; i<= m_length; i++)
        {
          if(n_City.getPop() > getEntry(i).getPop())
          {
            temp_pos++;
          }
          if (cgetEntry(i) == nullptr)
          {
            addBack(n_City);
            setEntry(temp_pos, n_City);
            m_length ++;
          }
          else
          {
            insert(i, n_City);
          }
        }
      }
    }
  }

  return (temp);
}
