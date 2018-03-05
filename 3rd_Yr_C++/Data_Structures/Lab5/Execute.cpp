#include "Execute.h"
#include <stdexcept>

Execute::Execute(std::string filename) {
	choice = 0;
	file.open(filename);
	TTT = new TwoThreeTree<int>();
	while (file >> value) {
		TTT->insert(value);
	}
	file.close();
}
Execute::~Execute() {
	delete TTT;
}
void Execute::run() {
	while (choice != 9) {
		std::cout << "..............................................................." << std::endl;
		std::cout << "Please choose one of the following commands" <<std::endl;
		std::cout << "1- Insert \n";
		std::cout << "2- DeleteMin \n";
		std::cout << "3- DeleteMax \n";
		std::cout << "4- FindMin \n";
	  std::cout << "5- FindMax \n";
		std::cout << "6- Find \n";
		std::cout << "7- Delete \n";
		std::cout << "8- Level order \n";
		std::cout << "9- Exit \n";
		std::cout << "" << std::endl;
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
					choice_7();
					break;
				case 8:
					std::cout <<"\n";
					choice_8();
					break;
				case 9:
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
		TTT->insert(value);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}

void Execute::choice_2() {
	if (!TTT->deleteMin()) {
		std::cout << "Tree is empty\n";
	};
}
void Execute::choice_3() {
	if (!TTT->deleteMax()) {
		std::cout << "Tree is empty\n";
	};
}
// find min value in tree
void Execute::choice_4() {
	if(!TTT->findMin()) {
		std::cout << "Tree is empty\n";
	}
}
//find max value in tree
void Execute::choice_5() {
	if(!TTT->findMax()) {
		std::cout << "Tree is empty\n";
	}
}
// find
void Execute::choice_6() {

}
// Delete
void Execute::choice_7() {
	std::cout << "Enter a number to be deleted:" << std::endl;
	std::cin >> input;
	try{
		value = std::stoi(input);
		TTT->deleteVal(value);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}
// level order
void Execute::choice_8() {
	TTT->level();
	std::cout << "\n";
}
