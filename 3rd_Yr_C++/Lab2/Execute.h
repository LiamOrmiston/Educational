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
#include "Hash.h"

class Execute {
public:
	Execute();
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
	Hash<int>* H;
	LinkedList<int> L;
};
#endif
