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
	// TODO: my_minmax = new MinMaxHeap();
}
// destructor
ExecuteLeftist::~ExecuteLeftist() {
  delete my_minmax;
}

// UI
void ExecuteLeftist::run() {
	while (choice != 7) {
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "Please choose one of the following commands:" << std::endl;
		std::cout << "1 - Insert" << std::endl;
		std::cout << "2 - deleteMin" << std::endl;
    std::cout << "3 - findMin" << std::endl;
		std::cout << "4 - findMax" << std::endl;
    std::cout << "5 - deleteMax" << std::endl;
    std::cout << "6 - levelOrder" << std::endl;
    std::cout << "7 - Exit" << std::endl;
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
        choice_6();
        break;
        case 7:
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
		my_minmax->insert(value);
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
	my_minmax->deleteMin();
}
// Find Min value
void ExecuteLeftist::choice_3() {
	my_minmax->findMin();
}
// Find Max value
void ExecuteLeftist::choice_4() {
 my_minmax->findMax();
}
// Delete Max value
void ExecuteLeftist::choice_5() {
	my_minmax->deleteMax();
}
// Print level-order
void ExecuteLeftist::choice_6() {
	my_minmax->levelOrder();
}
