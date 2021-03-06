/* Execute.cpp
 * Liam Ormiston
 * 1-29-18
 * Driver file
 */
#include "Execute.h"
// Open file and create linkedlist
Execute::Execute() {
	file.open("data.txt");
	while (file.good()) {
		file >> value;
		L.insert(value);
	}
	file.close();
}
// main menu for program
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
	// deconstructor call
	L.~LinkedList();
}
// Insert driver
void Execute::choice_1() {
	std::cout << "Enter a number to be inserted into the list:" << std::endl;
	std::cin >> input;
	try{
		choice = std::stoi(input);
		L.insert(choice);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}
// Delete driver
void Execute::choice_2() {
	std::cout << "Enter a number to be deleted from the list:" << std::endl;
	std::cin >> input;
	try{
		choice = std::stoi(input);
		L.erase(choice);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}
// Find driver
void Execute::choice_3() {
	std::cout << "Enter a number to be found:" << std::endl;
	std::cin >> input;
	try{
		choice = std::stoi(input);
		if (L.find(choice)) {
			std::cout << "Entered number exists in the list." << std::endl;
		}
		else {
			std::cout << "Entered number does not exist in the list." << std::endl;
		}
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}
// Print driver
void Execute::choice_4() {
  L.print();
}
