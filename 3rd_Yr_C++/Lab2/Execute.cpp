/*
 * Execute.cpp
 * Liam Ormiston
 * 2-5-18
 * Driver file for Hash methods
 */
#include "Execute.h"

Execute::Execute() {
	file.open("data.txt");
	file >> value;
	H = new Hash<int>(value);
	while (file.good()) {
		file >> value;
		H->hash_insert(value);
	}
	file.close();
}
void Execute::run() {
	while (choice != 5) {
		std::cout << "--------------------------------" << std::endl;
		std::cout << "Please choose one of the following commands:" << std::endl;
		std::cout << "1 - Insert" << std::endl;
		std::cout << "2 - Delete" << std::endl;
		std::cout << "3 - Find" << std::endl;
		std::cout << "4 - Print" << std::endl;
		std::cout << "5 - Exit" << std::endl;
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
					choice_1();
					break;
				case 2:
					choice_2();
					break;
				case 3:
					choice_3();
					break;
				case 4:
					choice_4();
					break;
				case 5:
					break;
				default:
					std::cout << "Invalid input. Please try again" << std::endl;
			}
		}
	}
	std::cout << "Exiting the program..." << std::endl;
	H->~Hash();
}
void Execute::choice_1() {
	std::cout << "Enter a number to be inserted:" << std::endl;
	std::cin >> input;
	try{
		choice = std::stoi(input);
		if(H->hash_insert(choice)) {
			std::cout << choice << " was added to the hash table" << std::endl;
		}
		else {	
		std::cout << choice << " exists already, it couldn’t be added to the hash table" << std::endl;
		}
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}

void Execute::choice_2() {
	std::cout << "Enter a number to delete:" << std::endl;
	std::cin >> input;
	try{
		choice = std::stoi(input);
		if(H->hash_delete(choice)) {
			std::cout << choice << " was deleted from the hash table" << std::endl;
		}
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}
void Execute::choice_3() {
	std::cout << "Enter a number to be found:" << std::endl;
	std::cin >> input;
	try{
		choice = std::stoi(input);
		if (H->hash_find(choice)) {
			std::cout << choice << " was found in the hash table" << std::endl;
		}
		else {
			std::cout << choice << " couldn't be found in the hash table" << std::endl;
		}
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}
void Execute::choice_4() {
	H->hash_print();
}
