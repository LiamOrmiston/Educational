Lab5: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o Lab5
main.o: main.cpp Executive.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Executive.o: Executive.cpp Executive.h Node.hpp Node.h LinkedList.hpp LinkedList.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Lab5
