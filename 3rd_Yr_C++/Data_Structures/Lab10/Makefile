Lab10: main.o ExecuteLeftist.o
	g++ -std=c++11 -g -Wall main.o ExecuteLeftist.o  -o Lab10
main.o: main.cpp ExecuteLeftist.h  LeftistHeap.h LeftistNode.h
	g++ -std=c++11 -g -Wall -c main.cpp
ExecuteLeftist.o: ExecuteLeftist.cpp ExecuteLeftist.h
	g++ -std=c++11 -g -Wall -c ExecuteLeftist.cpp
clean:
	rm *.o Lab10
