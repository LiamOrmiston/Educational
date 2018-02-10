/*
 * Execute.cpp
 * Liam Ormiston
 * 2-5-18
 * Driver file for Hash methods
 */
#include "Execute.h"
#include <stdexcept>
#include <iomainip>

Execute::Execute() {
	choice = 0;
	file.open("data.txt");
	QH = new QHash<int>();
	DH = new DHash<int>();
	while (file.good()) {
		file >> value;
		QH->qhash_insert(value);
		DH->dhash_insert(value);
	}
	file.close();
}
Execute::~Execute() {
	delete QH;
	delete DH;
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
					break;
				default:
					std::cout <<"\n";
					std::cout << "Invalid input. Please try again" << std::endl;
			}
		}
	}
	std::cout << "Exiting the program..." << std::endl;
}
void Execute::choice_1() {
	std::cout << "Enter a number to be inserted:" << std::endl;
	std::cin >> input;
	try{
		choice = std::stoi(input);
		if(QH->qhash_insert(choice)) {}
		else {	
			std::cout <<"failed to insert "<< choice << " into hash table with quadratic probing" << std::endl; 
		}
		if(DH->dhash_insert(choice)) {}
		else {	
			std::cout <<"failed to insert "<< choice << " into hash table with double hashing" << std::endl; 
		}
	std::cout.percision(3) << "Load factor of hash table with quadratic probing " << QH->getLF() << std::endl;
	std::cout.percision(3) << "Load factor of hash table with double hashing " << DH->getLF() << std::endl;
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
		if(QH->qhash_delete(choice)) {
			std::cout << choice << " was deleted from the qhash table" << std::endl;
		}
		else {	
			std::cout << choice << " doesn't exist, it couldn’t be deleted from the qhash table" << std::endl;
		}
		if(DH->dhash_delete(choice)) {
			std::cout << choice << " was deleted from the dhash table" << std::endl;
		}
		else {	
			std::cout << choice << " doesn't exist, it couldn’t be deleted from the dhash table" << std::endl;
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
		if (QH->qhash_find(choice)) {
			std::cout << choice << " was found in the qhash table" << std::endl;
		}
		else {
			std::cout << choice << " couldn't be found in the qhash table" << std::endl;
		}
		if (DH->dhash_find(choice)) {
			std::cout << choice << " was found in the dhash table" << std::endl;
		}
		else {
			std::cout << choice << " couldn't be found in the dhash table" << std::endl;
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
	QH->qhash_print();
	DH->dhash_print();
}
