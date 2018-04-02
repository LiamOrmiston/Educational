/*
 * ExecuteMax.cpp
 * Liam Ormiston
 * 4-2-18
 * Driver file for Hash methods
 */
#include "ExecuteMax.h"
#include <stdio.h>
#include <stdexcept>

ExecuteMax::ExecuteMax() {
	my_maxmin = new MaxMinHeap();
}
ExecuteMax::~ExecuteMax() {
  // delete MaxMinHeap;
}

void ExecuteMax::run() {
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
		try{
			choice = std::stoi (input);
		}
		catch(const std::invalid_argument e) {
			std::cout << "Invalid input. Please try again" << std::endl;
			argument = false;
		}
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
void ExecuteMax::choice_1() {
	std::cout << "Enter a number to be inserted:" << std::endl;
	std::cin >> input;
	std::cout <<"\n";

	try{
		value = std::stoi(input);
		my_maxmin->insert(value);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}

void ExecuteMax::choice_2() {
	my_maxmin->deleteMin();
}
void ExecuteMax::choice_3() {
	my_maxmin->findMin();
}
void ExecuteMax::choice_4() {
 my_maxmin->findMax();
}
void ExecuteMax::choice_5() {
	my_maxmin->deleteMax();
}
void ExecuteMax::choice_6() {
	my_maxmin->levelOrder();
}
