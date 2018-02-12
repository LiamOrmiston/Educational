/*
 * LinkedList.h
 * Liam Ormiston
 * 2-5-18
 * Header file for LinkedList class
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

template <typename T>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty() const;
		bool insert(T value);
		bool erase(T value);
		void print();
		bool find(T value);
		bool recur_erase(Node<T>* node, Node<T>* last, T value);
		int getValue();
	private:
		Node<T>* m_front;
		int m_length;
};
#include "LinkedList.hpp"
#endif
