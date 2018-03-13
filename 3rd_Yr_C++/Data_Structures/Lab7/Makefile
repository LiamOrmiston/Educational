Lab7: main.o Execute.o
	g++ -std=c++11 -g -Wall main.o Execute.o -o Lab7
main.o: main.cpp Execute.h MinHeap.h
	g++ -std=c++11 -g -Wall -c main.cpp
Execute.o: Execute.cpp Execute.h
	g++ -std=c++11 -g -Wall -c Execute.cpp
clean:
	rm *.o Lab7
