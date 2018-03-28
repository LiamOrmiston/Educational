/*
 * Execute.h
 * Liam Ormiston
 * 3-27-18
 * Driver header file
 */
#ifndef EXECUTE_H
#define EXECUTE_H
#include <string>
#include <iostream>
#include <fstream>
#include "MinHeap.h"

class Execute {
	public:
		Execute();
		~Execute();
		void run();
		void choice_1();
		void choice_2();
    void choice_3();
    void choice_4();
    void choice_5();
    void choice_6();
  private:
    std::ifstream file;
    std::string input;
    int value;
    int choice;
    // initalize MinHeap;
		MinHeap* my_min;
  };
  #endif
