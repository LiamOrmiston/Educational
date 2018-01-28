#ifndef HEAP_H
#define HEAP_H
#include "EmptyHeap.h"

template <typename T>
class Heap
{
public:
	Heap(int initialSize);
	Heap(const Heap<T>& heap); // The copy constructor
	~Heap();

	void add(T& newItem);
	bool isEmpty() const;
	void remove() throw (EmptyHeap);
	T peekTop() const throw (EmptyHeap);
	void rebuildHeap(int newPatPos);
private:
	T* theCompleteBinaryTree;
	int sizeOfArray;
	int numItemsInHeap;
};
#include "Heap.hpp"
#endif
