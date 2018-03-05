Lab4: main.o Execute.o
	g++ -std=c++11 -g -Wall main.o Execute.o -o Lab5
main.o: main.cpp Execute.h TwoThreeNode.h TwoThreeTree.h
	g++ -std=c++11 -g -Wall -c main.cpp
Execute.o: Execute.cpp Execute.h
	g++ -std=c++11 -g -Wall -c Execute.cpp
clean:
	rm *.o Lab5
