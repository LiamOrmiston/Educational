/* Execute.h
 * Liam Ormiston
 * 1-29-18
 * Driver file
 */
#ifndef EXECUTE_H
#define EXECUTE_H
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

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
	LinkedList<int> L;
};
#endif
