Lab8: main.o Pokemon.o NotFoundException.o
	g++ -std=c++11 -g -Wall main.o Pokemon.o NotFoundException.o -o Lab8

main.o: main.cpp Pokemon.h
	g++ -std=c++11 -g -Wall -c main.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

NotFoundException.o: NotFoundException.cpp NotFoundException.h
	g++ -std=c++11 -g -Wall -c NotFoundException.cpp
clean:
	rm *.o Lab8
