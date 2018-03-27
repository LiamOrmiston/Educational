Lab7: main.o Execute.o MinHeap.o
	g++ -std=c++11 -g -Wall main.o Execute.o MinHeap.o -o Lab7
main.o: main.cpp Execute.h MinHeap.h
	g++ -std=c++11 -g -Wall -c main.cpp
Execute.o: Execute.cpp Execute.h MinHeap.h
	g++ -std=c++11 -g -Wall -c Execute.cpp
MinHeap.o: MinHeap.cpp MinHeap.h
	g++ -std=c++11 -g -Wall -c MinHeap.cpp
clean:
	rm *.o Lab7
