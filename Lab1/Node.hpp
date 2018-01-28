/*
Node.hpp
Liam Ormiston
1-29-18
File for the Node class
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

//Constructor
template <typename T>
Node<T>::Node()
{
  m_next = nullptr;
  m_value = "";
}

//Setters
template <typename T>
void Node<T>::setValue(T value) {
  m_value = value;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
  m_next = next;
}

//Getters
template <typename T>
T Node<T>::getValue() {
  return(m_value);
}

template <typename T>
Node<T>* Node<T>::getNext() {
  return(m_next);
}
