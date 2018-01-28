/* Execute.cpp
 * Liam Ormiston
 * 1-29-18
 * Driver file
 */
#include "Execute.h"
void Execute::Execute() {}
void Execute::run() {
	file.open("data.txt");
	while (choice != 5) {
		std::cout << "--------------------------------" << std::endl;
		std::cout << "Please choose one of the following commands:" << std::endl;
		std::cout << "1 - Insert" << std::endl;
		std::cout << "2 - Delete" << std::endl;
		std::cout << "3 - Find" << std::endl;
		std::cout << "4 - Print" << std::endl;
		std::cout << "5 - Exit" << std::endl;
		std::cin >> input;
		switch (std::stoi(user)) {
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
				choice_5();
				break;
			default:
				std::cout << "Invalid input. Please try again" << std::endl;
		}
	}
	std::cout << "Exiting the program..." << std::endl;
	file.close();
	list.~LinkedList();
}
void Execute::choice_1() {
	std::cout << "Enter a number to be inserted into the list:" << std::endl;
	std::cin >> value;
	if (find(value) == nullptr) {
		list.insert(value);
	}
	else {
		std::cout << "Number already exists in the list" << std::endl;
	}
}

void Execute:choice_4() {
	std::cout << "List: ";
	list.print();
	std::endl;
}
