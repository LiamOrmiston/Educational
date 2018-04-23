Lab10: main.o ExecuteLeftist.o ExecuteSkew.o
	g++ -std=c++11 -g -Wall main.o ExecuteLeftist.o ExecuteSkew.o -o Lab10
main.o: main.cpp ExecuteLeftist.h ExecuteSkew.h LeftistHeap.h LeftistNode.h SkewHeap.h SkewNode.h
	g++ -std=c++11 -g -Wall -c main.cpp
ExecuteLeftist.o: ExecuteLeftist.cpp ExecuteLeftist.h
	g++ -std=c++11 -g -Wall -c ExecuteLeftist.cpp
ExecuteSkew.o: ExecuteSkew.cpp ExecuteSkew.h
	g++ -std=c++11 -g -Wall -c ExecuteSkew.cpp
clean:
	rm *.o Lab10
