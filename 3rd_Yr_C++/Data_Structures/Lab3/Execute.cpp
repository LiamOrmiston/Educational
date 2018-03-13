/*
 * Execute.cpp
 * Liam Ormiston
 * 2-5-18
 * Driver file for Hash methods
 */
#include "Execute.h"
#include <stdexcept>

Execute::Execute(std::string filename) {
	choice = 0;
	file.open(filename);
	QH = new QHash<int>();
	DH = new DHash<int>();
	while (file.good()) {
		file >> value;
		if (!QH->qhash_find(value)) {
			QH->qhash_insert(value);
		}
		if (!DH->dhash_find(value)) {
			DH->dhash_insert(value);
		}
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
		value = std::stoi(input);
		if(QH->qhash_insert(value)) {}
		else {
			std::cout <<"failed to insert "<< value << " into hash table with quadratic probing" << std::endl;
		}
		if(DH->dhash_insert(value)) {}
		else {
			std::cout <<"failed to insert "<< value << " into hash table with double hashing" << std::endl;
		}
		printf("Load factor of hash table with quadratic probing is %.2f\n", QH->getLF());
		printf("Load factor of hash table with double hashing is %.2f\n", DH->getLF());
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
		value = std::stoi(input);
		if(QH->qhash_delete(value)) {
			std::cout << "Successfully deleted "<< value << " from the hash table with quadratic probing" << std::endl;
		}
		else {
			std::cout << value << " doesn't exist in the hash table with quadratic probing" << std::endl;
		}
		if(DH->dhash_delete(value)) {
			std::cout << "Successfully deleted "<< value << " from the hash table with double hashing" << std::endl;
		}
		else {
			std::cout << value << " doesn't exist in the hash table with double hashing" << std::endl;
		}
		printf("Load factor of hash table with quadratic probing is %.2f\n", QH->getLF());
		printf("Load factor of hash table with double hashing is %.2f\n", DH->getLF());
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
		value = std::stoi(input);
		if (QH->qhash_find(value)) {
			std::cout << value << " exists in the hash table with quadratic probing" << std::endl;
		}
		else {
			std::cout << value << " does not exist in the hash table with quadratic probing" << std::endl;
		}
		if (DH->dhash_find(value)) {
			std::cout << value << " exists in the hash table with double hashing" << std::endl;
		}
		else {
			std::cout << value << " does not exist in the hash table with double hashing" << std::endl;
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
