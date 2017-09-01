Lab1: main.o executive.o vpr.o
	g++ -std=c++11 -g -Wall main.o executive.o vpr.o -o Lab1

main.o: main.cpp executive.h vpr.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

vpr.o: vpr.h vpr.cpp
	g++ -std=c++11 -g -Wall -c vpr.cpp

clean:
	rm *.o Lab1
