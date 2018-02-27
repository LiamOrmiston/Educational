#ifndef EXECUTE_H
#define EXECUTE_H
#include <string>
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

class Execute {
	public:
		Execute(std::string filename);
		~Execute();
		void run();
		void choice_1();
		void choice_2();
		void choice_3();
		void choice_4();
		void choice_5();
		void choice_6();
		void choice_7();
		void choice_8();
		void choice_9();
		
	private:
		std::ifstream file;
		std::string input;
		int value;
		int choice;
		BinarySearchTree<int>* BST;
};
#endif
