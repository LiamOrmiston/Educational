Lab8: main.o Execute.o ExecuteMax.o MinMaxHeap.o MaxMinHeap.o
	g++ -std=c++11 -g -Wall main.o Execute.o ExecuteMax.o MinMaxHeap.o MaxMinHeap.o -o Lab8
main.o: main.cpp Execute.h MinMaxHeap.h MaxMinHeap.h
	g++ -std=c++11 -g -Wall -c main.cpp
Execute.o: Execute.cpp Execute.h MinMaxHeap.h
	g++ -std=c++11 -g -Wall -c Execute.cpp
ExecuteMax.o: ExecuteMax.cpp ExecuteMax.h MaxMinHeap.h
	g++ -std=c++11 -g -Wall -c ExecuteMax.cpp
MinMaxHeap.o: MinMaxHeap.cpp MinMaxHeap.h
	g++ -std=c++11 -g -Wall -c MinMaxHeap.cpp
MaxMinHeap.o: MaxMinHeap.cpp MaxMinHeap.h
	g++ -std=c++11 -g -Wall -c MaxMinHeap.cpp
clean:
	rm *.o Lab8
