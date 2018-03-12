/*
 * LinkedList.cpp
 * Liam Ormiston
 * 3-12-18
 * File for LinkedList class
 */
#include <iostream>
#include <fstream>
#include "LinkedList.h"

// LinkedList constructor
template <typename T>
LinkedList<T>::LinkedList() {
	// initializes length of list to 0 and the first pointer to nullptr
	m_front = nullptr;
	m_length = 0;
}

// LinkedList destructor
template <typename T>
LinkedList<T>::~LinkedList() {
	// creates node pointer to keep track of the current value in the list
	Node<T>* current = m_front;
	Node<T>* next = nullptr;
	// walk the list and destroy every value
	while( current != nullptr )
	{
		next = current->getNext();
		delete current;
		current = next;
	}
	m_front = nullptr;
}

// checks to see if the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const {
	if(m_front == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

// insert method
template <typename T>
bool LinkedList<T>::insert(T value) {
	// checks first to see if the list is empty
	if(isEmpty()) {
		// if so, set first node to the value
		m_front = new Node<T>();
		m_front -> setValue(value);
	}
	// checks to see if the value is already in the list
	else if(find(value)) {
		// if so, let user know and end function call
		return false;
	}
	// adds the value to the front value
	else {
		Node<T>* temp_front = new Node<T>();
		temp_front -> setValue(value);
		temp_front -> setNext(m_front);
		m_front = temp_front;
		}
		m_length++;
		return true;
	}

// recursive erase method
template <typename T>
bool LinkedList<T>::recur_erase(Node<T>* node, Node<T>* last, T value) {
	// checks if the first node is equal to the value we want to erase
	if(last->getValue() == value) {
		// if so, erase
		m_front = node;
		delete last;
	}
	// if current node isn't the value we want to erase, try again with
	// the next node
	else if (node->getValue() != value) {
		recur_erase(node->getNext(), node, value);
	}
	// current node is the value we want to erase
	else {
		// create a node pointer to look at the next value
		Node<T>* temp = node->getNext();
		// delete
		delete node;
		// repair list
		last->setNext(temp);
	}
	return true;
}

// erase method helper
template <typename T>
bool LinkedList<T>::erase(T value) {
	// checks if the value is in the list
	if(!find(value)){
		// if not, notify user and end method call
		std::cout << value << " couldn't be found in the hash table" << std::endl;
		return false;
	}
	// if value is in the list, call recursive erase method
	else {
		return (recur_erase(m_front->getNext(), m_front, value));
	}
	return false;
}

// print method
template <typename T>
void LinkedList<T>::print() {
	// create a node pointer that looks at current node
	Node<T>* temp = m_front;
	// prints the value until end of list
	while(temp != nullptr) {
		std::cout << temp->getValue();
		std::cout << " ";
		temp = temp->getNext();
	}
	std::cout << std::endl;
}

// find method
template <typename T>
bool LinkedList<T>::find(T value) {
	// checks if the list is empty
	if(isEmpty()) {
		return false;
	}
	else if(m_front->getValue() == value) {
		return true;
	}
	else {
		return false;
	}
}
