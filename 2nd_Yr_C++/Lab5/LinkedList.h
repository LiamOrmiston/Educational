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
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <typename T>
class LinkedList
{
	public:

	LinkedList();
	/** @pre None.
	*   @post An empty list is created.
	*/

	~LinkedList();
	/** @pre None.
	*   @post Deletes all nodes in the list.
	*/

	bool isEmpty() const;
	/** @pre None.
	*   @post None.
	*   @return true if the list is empty, false otherwise.
	*/

  void addFront(T value);
	/** @pre the value is a valid T.
	*   @post One new element added to the front of the list.
	*   @return none.
	*/

	void addBack(T value);
	/** @pre the value is a valid T.
	*   @post One new element added to the end of the list.
	*   @return none.
	*/

  int getLength() const;
	/** @pre None.
	*   @post None.
	*   @return the number of elements in the list.
	*/

	T getEntry(int position) const;
	/** @pre None
	*   @post None
	*   @return The entry at the given position.
	* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
	*/

  void reverseList();

	private:
	Node<T>* m_front;
	int m_length;
  void flip(Node<T>* temp);
};

#include "LinkedList.hpp"
#endif
