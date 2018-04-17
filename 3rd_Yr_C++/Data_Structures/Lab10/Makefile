Lab10: main.o ExecuteLeftist.o ExecuteSkew.o LeftistHeap.o MaxMinHeap.o
	g++ -std=c++11 -g -Wall main.o ExecuteLeftist.o ExecuteSkew.o LeftistHeap.o MaxMinHeap.o -o Lab10
main.o: main.cpp ExecuteLeftist.h ExecuteSkew.h LeftistHeap.h MaxMinHeap.h
	g++ -std=c++11 -g -Wall -c main.cpp
ExecuteLeftist.o: ExecuteLeftist.cpp ExecuteLeftist.h LeftistHeap.h
	g++ -std=c++11 -g -Wall -c ExecuteLeftist.cpp
ExecuteSkew.o: ExecuteSkew.cpp ExecuteSkew.h MaxMinHeap.h
	g++ -std=c++11 -g -Wall -c ExecuteSkew.cpp
LeftistHeap.o: LeftistHeap.cpp LeftistHeap.h
	g++ -std=c++11 -g -Wall -c LeftistHeap.cpp
MaxMinHeap.o: MaxMinHeap.cpp MaxMinHeap.h
	g++ -std=c++11 -g -Wall -c MaxMinHeap.cpp
clean:
	rm *.o Lab10
