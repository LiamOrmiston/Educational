Lab1: main.o Execute.o
	g++ -std=c++11 -g -Wall main.o Execute.o -o Lab1
main.o: main.cpp Execute.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Execute.o: Execute.cpp Execute.h Node.hpp Node.h LinkedList.h 
	g++ -std=c++11 -g -Wall -c Execute.cpp
clean:
	rm *.o Lab1
