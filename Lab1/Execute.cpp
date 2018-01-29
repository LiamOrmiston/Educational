/* Execute.cpp
 * Liam Ormiston
 * 1-29-18
 * Driver file
 */
#include "Execute.h"
Execute::Execute() {
	std::cout << "opening file" << std::endl;
	file.open("data.txt");
	while (file.good()) {
		std::cout << "inserting ";
		file >> value;
		std::cout << value << std::endl;
		L.insert(value);
		// L.print();
	}
	std::cout << "closing file" << std::endl;
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
		choice = std::stoi (input);
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
				choice_5();
				break;
			default:
				std::cout << "Invalid input. Please try again" << std::endl;
		}
	}
	std::cout << "Exiting the program..." << std::endl;
	L.~LinkedList();
}
void Execute::choice_1() {
	std::cout << "Enter a number to be inserted into the list:" << std::endl;
	std::cin >> value;
	// if (L.find(value)) {
	// 	std::cout << "Number already exists in the list" << std::endl;
	// }
	// else {
	// 	L.insert(value);
	// }
	L.insert(value);
}

void Execute::choice_2() {
}
void Execute::choice_3() {
}
void Execute::choice_4() {
	std::cout << "calling print" << std::endl;
  L.print();
}
void Execute::choice_5() {
}
