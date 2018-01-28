Lab3: main.o Executive.o MathTools.o NegativeDiscriminant.o NoIntersection.o CannotDetermineRoomDimensions.o
	g++ -std=c++11 -g -Wall main.o Executive.o MathTools.o NegativeDiscriminant.o NoIntersection.o CannotDetermineRoomDimensions.o -o Lab3

main.o: main.cpp Executive.h MathTools.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

MathTools.o: MathTools.h MathTools.cpp MathToolsInterface.h
	g++ -std=c++11 -g -Wall -c MathTools.cpp

NegativeDiscriminant.o: NegativeDiscriminant.h NegativeDiscriminant.cpp
	g++ -std=c++11 -g -Wall -c NegativeDiscriminant.cpp

NoIntersection.o: NoIntersection.h NoIntersection.cpp
	g++ -std=c++11 -g -Wall -c NoIntersection.cpp

CannotDetermineRoomDimensions.o: CannotDetermineRoomDimensions.h CannotDetermineRoomDimensions.cpp
	g++ -std=c++11 -g -Wall -c CannotDetermineRoomDimensions.cpp

clean:
	rm *.o Lab3
