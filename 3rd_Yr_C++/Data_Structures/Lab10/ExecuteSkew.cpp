/*
 * ExecuteSkew.cpp
 * Liam Ormiston
 * 4-24-18
 * Driver file for Min-Skew Heap methods
 */
#include "ExecuteSkew.h"
#include <stdio.h>
#include <stdexcept>

// constructor
ExecuteSkew::ExecuteSkew() {
  // initalize SkewHeap;
  SH = new SkewHeap<int>();
}
// destructor
ExecuteSkew::~ExecuteSkew() {
  delete SH;
}

// UI
void ExecuteSkew::run() {
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
		// ExecuteSkews proper functions depending on user's request
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
void ExecuteSkew::choice_1() {
	std::cout << "Enter a number to be inserted:" << std::endl;
	std::cin >> input;
	std::cout <<"\n";
	// error catching for improper input
	try{
		value = std::stoi(input);
		SH->insert(value);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}

// Delete Min value
void ExecuteSkew::choice_2() {
	SH->deleteMin();
}
// Print pre-order
void ExecuteSkew::choice_3() {
	std::cout << "preorder: ";
  SH->pre();
}
// Print in-order
void ExecuteSkew::choice_4() {
 std::cout << "inorder: ";
 SH->in();
}
// Print level-order
void ExecuteSkew::choice_5() {
  std::cout << "levelorder:" << '\n';
	SH->level();
}
