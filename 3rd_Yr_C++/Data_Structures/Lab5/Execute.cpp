#include "Execute.h"
#include <stdexcept>

Execute::Execute(std::string filename) {
	choice = 0;
	file.open(filename);
	BST = new BinarySearchTree<int>();
	while (file >> value) {
		BST->add(value);
	}
	file.close();
}
Execute::~Execute() {
	delete BST;
}
void Execute::run() {
	while (choice != 10) {
		std::cout << "..............................................................." << std::endl;
		std::cout << "Please choose one of the following commands" <<std::endl;
		std::cout << "1- Insert \n";
		std::cout << "2- DeleteMin \n";
		std::cout << "3- DeleteMax \n";
		std::cout << "4- Delete \n";
	  std::cout << "5- FindMin \n";
		std::cout << "6- FindMax \n";
		std::cout << "7- PreOrder \n";
		std::cout << "8- InOrder \n";
		std::cout << "9- PostOrder \n";
		std::cout << "10- Exit \n";
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
					choice_9();
					break;
				case 10:
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
		BST->add(value);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}

void Execute::choice_2() {
	if (!BST->deleteMin()) {
		std::cout << "Tree is empty\n";
	};
}
void Execute::choice_3() {
	if (!BST->deleteMax()) {
		std::cout << "Tree is empty\n";
	};
}
void Execute::choice_4() {
	std::cout << "Enter a number to be deleted:" << std::endl;
	std::cin >> input;
	try{
		value = std::stoi(input);
		BST->deleteVal(value);
	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}
void Execute::choice_5() {
	if(!BST->findMin()) {
		std::cout << "Tree is empty\n";
	}
}
void Execute::choice_6() {
	if(!BST->findMax()) {
		std::cout << "Tree is empty\n";
	}
}
// PreOrder
void Execute::choice_7() {
	BST->pre();
	std::cout << "\n";
}
void Execute::choice_8() {
	BST->in();
	std::cout << "\n";
}
void Execute::choice_9() {
	BST->post();
	std::cout << "\n";
}
