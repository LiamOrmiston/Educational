#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Heap.h"
#include "EmptyPriorityQueue.h"

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue(int initialSize);
	PriorityQueue(const PriorityQueue<T>& pq); // The copy constructor
	~PriorityQueue();

	void enqueue(T newEntry);
	void dequeue() throw (EmptyPriorityQueue);
	bool isEmpty() const;
	T peekFront() const throw (EmptyPriorityQueue);
private:
	Heap<T>* theHeap;
};
#include "PriorityQueue.hpp"
#endif
