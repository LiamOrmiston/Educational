Lab6: main.o executive.o mazeReader.o mazeWalker.o mazeException.o
	g++ -std=c++11 -g -Wall main.o mazeReader.o mazeWalker.o mazeException.o executive.o -o Lab6

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.cpp executive.h mazeReader.h mazeWalker.h
	g++ -std=c++11 -g -Wall -c executive.cpp

mazeReader.o: mazeReader.h mazeReader.cpp mazeException.h
	g++ -std=c++11 -g -Wall -c mazeReader.cpp

mazeWalker.o: mazeWalker.h mazeWalker.cpp
	g++ -std=c++11 -g -Wall -c mazeWalker.cpp

mazeException.o: mazeException.cpp mazeException.h
	g++ -std=c++11 -g -Wall -c mazeException.cpp

clean:
	rm *.o Lab6
