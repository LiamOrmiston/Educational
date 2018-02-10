/*
 * Execute.h
 * Liam Ormiston
 * 2-5-18
 * Driver header file
 */
#ifndef EXECUTE_H
#define EXECUTE_H
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Q_Hash.h"
#include "D_Hash.h"

class Execute {
	public:
		Execute();
		~Execute();
		void run();
		void choice_1();
		void choice_2();
		void choice_3();
		void choice_4();
	private:
		std::ifstream file;
		std::string input;
		int value;
		int choice;
		DHash<int>* DH;
		QHash<int>* QH;
		LinkedList<int> L;
};
#endif
