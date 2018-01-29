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

template <typename T>
void LinkedList<T>::recur_insert(Node<T>* node, T value) {
	if(node->getNext() != nullptr) {
		recur_insert(node->getNext(), value);
	}
	else {
		Node<T>* temp = new Node<T>();
		temp->setValue(value);
		node -> setNext(temp);
	}
}

template <typename T>
bool LinkedList<T>::insert(T value) {
	if(isEmpty()) {
		m_front = new Node<T>();
		m_front -> setValue(value);
		m_length++;
	}
	else if(find(value)) {
		return false;
	}
	else {
		Node<T>* temp_front = new Node<T>();
		temp_front = m_front;
		recur_insert(temp_front, value);
		}
		m_length++;
		return true;
	}
template <typename T>
bool LinkedList<T>::recur_erase(Node<T>* node, Node<T>* last, T value) {
	if(last->getValue() == value) {
		m_front = node;
		delete last;
	}
	else if (node->getValue() != value) {
		recur_erase(node->getNext(), node, value);
	}
	else {
		Node<T>* temp = node->getNext();
		delete node;
		last->setNext(temp);
	}
	return true;
}

template <typename T>
bool LinkedList<T>::erase(T value) {
	if(!find(value)){
		std::cout << "Entered number does not exist in the list." << std::endl;
		return false;
	}
	else {
		return (recur_erase(m_front->getNext(), m_front, value));
	}
	return false;
}
template <typename T>
void LinkedList<T>::print() {
	Node<T>* temp = m_front;
	std::cout << "List: ";
	while(temp != nullptr) {
		std::cout << temp->getValue();
		std::cout << " ";
		temp = temp->getNext();
	}
	std::cout << std::endl;
}
template <typename T>
bool LinkedList<T>::find(T value) {
	if(isEmpty()) {
		return false;
	}
	else {
		Node<T>* temp = m_front;
		while(temp != nullptr) {
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
