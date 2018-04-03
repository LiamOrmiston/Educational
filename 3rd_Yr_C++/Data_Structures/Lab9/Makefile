Lab9: main.o Execute.o MaxHeap.o MinHeap.o
	g++ -std=c++11 -g -Wall main.o Execute.o MaxHeap.o MinHeap.o -o Lab9
main.o: main.cpp Execute.h BinaryNode.h BinarySearchTree.h MaxHeap.h MinHeap.h
	g++ -std=c++11 -g -Wall -c main.cpp
Execute.o: Execute.cpp Execute.h BinarySearchTree.h MaxHeap.h MinHeap.h
	g++ -std=c++11 -g -Wall -c Execute.cpp
MaxHeap.o: MaxHeap.cpp MaxHeap.h
	g++ -std=c++11 -g -Wall -c MaxHeap.cpp
MinHeap.o: MinHeap.cpp MinHeap.h
	g++ -std=c++11 -g -Wall -c MinHeap.cpp
clean:
	rm *.o Lab9
