/*
 * ExecuteLeftist.cpp
 * Liam Ormiston
 * 4-24-18
 * Driver file for Min-Leftist Heap methods
 */
#include "ExecuteLeftist.h"
#include <stdio.h>
#include <stdexcept>

// constructor
ExecuteLeftist::ExecuteLeftist() {
  // initalize LeftistHeap;
  LH = new LeftistHeap<int>();
}
// destructor
ExecuteLeftist::~ExecuteLeftist() {
  delete LH;
}

// UI
void ExecuteLeftist::run() {
	while (choice != 6) {
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "Please choose one of the following commands:" << std::endl;
		std::cout << "1 - Insert" << std::endl;
		std::cout << "2 - deleteMin" << std::endl;
    std::cout << "3 - pre" << std::endl;
		std::cout << "4 - in" << std::endl;
    std::cout << "5 - level" << std::endl;
    std::cout << "6 - end" << std::endl;
		std::cin >> input;
		bool argument = true;
		// checks for correct input
		try{
			choice = std::stoi (input);
		}
		catch(const std::invalid_argument e) {
			std::cout << "Invalid input. Please try again" << std::endl;
			argument = false;
		}
		// ExecuteLeftists proper functions depending on user's request
		if (argument) {
      switch (choice) {
        case 1:
          std::cout <<"\n";
          choice_1();
          break;
        case 2:
          std::cout <<"\n";
          choice_2();
          break;
        case 3:
          std::cout <<"\n";
          choice_3();
          break;
        case 4:
          std::cout <<"\n";
          choice_4();
          break;
        case 5:
          std::cout <<"\n";
          choice_5();
          break;
        case 6:
          std::cout <<"\n";
          break;
        default:
					std::cout <<"\n";
					std::cout << "Invalid input. Please try again" << std::endl;
			}
		}
	}
	std::cout << "Exiting the program..." << std::endl;
}
// Insert
void ExecuteLeftist::choice_1() {
	std::cout << "Enter a number to be inserted:" << std::endl;
	std::cin >> input;
	std::cout <<"\n";
	// error catching for improper input
	try{
		value = std::stoi(input);
		LH->insert(value);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}

// Delete Min value
void ExecuteLeftist::choice_2() {
	LH->deleteMin();
}
// Print pre-order
void ExecuteLeftist::choice_3() {
	LH->pre();
}
// Print in-order
void ExecuteLeftist::choice_4() {
 LH->in();
}
// Print level-order
void ExecuteLeftist::choice_5() {
	LH->level();
}
