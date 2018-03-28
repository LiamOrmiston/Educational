Lab7_max: mainMax.o ExecuteMax.o MaxHeap.o
	g++ -std=c++11 -g -Wall mainMax.o ExecuteMax.o MaxHeap.o -o Lab7_max
mainMax.o: mainMax.cpp ExecuteMax.h MaxHeap.h
	g++ -std=c++11 -g -Wall -c mainMax.cpp
ExecuteMax.o: ExecuteMax.cpp ExecuteMax.h MaxHeap.h
	g++ -std=c++11 -g -Wall -c ExecuteMax.cpp
MaxHeap.o: MaxHeap.cpp MaxHeap.h
	g++ -std=c++11 -g -Wall -c MaxHeap.cpp
clean:
	rm *.o Lab7_max
