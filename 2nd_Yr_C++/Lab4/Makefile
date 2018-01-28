Lab4: main.o Executive.o PreconditionViolationException.o
	g++ -std=c++11 -g -Wall main.o Executive.o PreconditionViolationException.o -o Lab4

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp StackInterface.h QueueInterface.h Stack.h Queue.h Stack.hpp Queue.hpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp

clean:
	rm *.o Lab4
