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
template <typename T>
Node<T>::Node()
{
  m_next = nullptr;
  m_previous = nullptr;
}

//Set value of m_value
template <typename T>
void Node<T>::setValue(T val)
{
  m_value = val;
}

//Return m_value
template <typename T>
T Node<T>::getValue() const
  {
    return(m_value);
  }

//Set value of m_next
template <typename T>
void Node<T>::setNext(Node<T>* next)
{
  m_next = next;
}

//Return m_next
template <typename T>
Node<T>* Node<T>::getNext() const
  {
    return(m_next);
  }

//Set value of m_previous
template <typename T>
void Node<T>::setPrev(Node<T>* prev)
{
  m_previous = prev;
}

//Return m_previous
template <typename T>
Node<T>* Node<T>::getPrev() const
  {
    return(m_previous);
  }
