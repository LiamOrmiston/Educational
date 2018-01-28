/*
   LinkedList.cpp
   Liam Ormiston
   1-29-18
   File for LinkedList class
   */

#include <iostream>
#include <fstream>
#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
	m_front = null;
	m_length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* current = m_front;
	while( current != nullptr )
	{
		Node<T>* next = current -> getNext();
		delete current;
		current = next;
	}
	m_front = nullptr;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
	if(m_front == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//TODO: recursive implementation
template <typename T>
bool LinkedList<T>::insert(T value) {
	if(find(value) != null) {
		return false;
	}
	else {
		if(isEmpty())
		{
			m_front = new Node<T>();
			m_front -> setValue(value);
			m_length++;
		}
		else {
			Node<T>* temp;
			temp = new Node<T>(); //TODO: clean up
			temp -> setValue(value);
			temp -> setNext(m_front);
			m_front = temp;
			m_length ++;
		}
	}
}

//TODO: recursive implementation
template <typename T>
bool LinkedList<T>::erase(T value) {
}
template <typename T>
void LinkedList<T>::print() {
	for(int i=0; i<m_length; i++) {
		std::cout << temp->getValue() " ";
		temp = temp->getNext();
	}
}
template <typename T>
bool LinkedList<T>::find(T value) {
	if(isEmpty()) {
		return false;
	}
	else {
		Node<T>* temp = nullptr;
		temp = m_front;
		for(int i=0; i<m_length; i++) {
			if(temp->getValue() == value) {
				return true;
			}
			else {
				temp = temp->getNext();
			}
		}
		return false;
	}
}
}
}
