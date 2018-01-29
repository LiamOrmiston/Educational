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
	m_front = nullptr;
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
void LinkedList<T>::recur_insert(Node<T>* node, T value) {
	if(node->getNext() != nullptr) {
		std::cout << "attempting to recurs" << std::endl;
		recur_insert(node->getNext(), value);
	}
	else {
		std::cout << "attempting to set value in recurs func" << std::endl;
		Node<T>* temp = new Node<T>();
		std::cout << "creating temp Node" << std::endl;
		temp->setValue(value);
		std::cout << "setting node to temp" << std::endl;
		node -> setNext(temp);
	}
}
template <typename T>
bool LinkedList<T>::insert(T value) {
	if(isEmpty()) {
		std::cout <<"list is empty" <<std::endl;
		m_front = new Node<T>();
		m_front -> setValue(value);
		m_length++;
	}
	// else if(find(value)) {
	// 	return false;
	// }
	else {
		std::cout << "going inside recurs func" << std::endl;
		Node<T>* temp_front = new Node<T>();
		temp_front = m_front;
		recur_insert(temp_front, value);
		}
		std::cout << "success" << std::endl;
		m_length++;
		return true;
	}

//TODO: recursive implementation
template <typename T>
bool LinkedList<T>::erase(T value) {
}
template <typename T>
void LinkedList<T>::print() {
	std::cout <<"inside print and printing m_front"<<std::endl;
	std::cout << m_front->getValue() << std::endl;
	Node<T>* temp = m_front;
	std::cout <<"created temp"<<std::endl;
	std::cout << "List: ";
	for(int i=0; i<m_length; temp = temp->getNext()) {
		std::cout << temp->getValue();
	}
	std::cout << std::endl;
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
				std::cout << "inside find method if" << std::endl;
				return true;
			}
			else {
				temp = temp->getNext();
				std::cout << "inside find method else" << std::endl;
			}
		}
		return false;
	}
}
