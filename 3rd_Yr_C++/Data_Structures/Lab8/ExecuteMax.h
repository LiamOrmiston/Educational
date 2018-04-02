/*
 * ExecuteMax.h
 * Liam Ormiston
 * 4-2-18
 * Driver header file
 */
#ifndef EXECUTE_MAX_H
#define EXECUTE_MAX_H
#include <string>
#include <iostream>
#include <fstream>
#include "MaxMinHeap.h"

class ExecuteMax {
	public:
		ExecuteMax();
		~ExecuteMax();
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
    // initalize MaxMinHeap;
		MaxMinHeap* my_maxmin;
  };
  #endif
