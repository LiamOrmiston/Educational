Lab2: main.o MedicalExecutive.o City.o
	g++ -std=c++11 -g -Wall main.o MedicalExecutive.o City.o -o Lab2

main.o: main.cpp MedicalExecutive.h City.h Node.h Node.hpp LinkedList.h LinkedList.h
	g++ -std=c++11 -g -Wall -c main.cpp

MedicalExecutive.o: MedicalExecutive.h MedicalExecutive.cpp
	g++ -std=c++11 -g -Wall -c MedicalExecutive.cpp

City.o: City.h City.cpp
	g++ -std=c++11 -g -Wall -c City.cpp

clean:
	rm *.o Lab2
