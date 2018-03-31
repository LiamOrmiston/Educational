Lab8: main.o Execute.o MinMaxHeap.o
	g++ -std=c++11 -g -Wall main.o Execute.o MinMaxHeap.o -o Lab8
main.o: main.cpp Execute.h MinMaxHeap.h
	g++ -std=c++11 -g -Wall -c main.cpp
Execute.o: Execute.cpp Execute.h MinMaxHeap.h
	g++ -std=c++11 -g -Wall -c Execute.cpp
MinMaxHeap.o: MinMaxHeap.cpp MinMaxHeap.h
	g++ -std=c++11 -g -Wall -c MinMaxHeap.cpp
clean:
	rm *.o Lab8
