/*
 * ExecuteSkew.h
 * Liam Ormiston
 * 4-24-18
 * Driver header file
 */
#ifndef EXECUTE_SKEW_H
#define EXECUTE_SKEW_H
#include <string>
#include <iostream>
#include <fstream>
#include "SkewHeap.h"

class ExecuteSkew {
	public:
		ExecuteSkew();
		~ExecuteSkew();
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
    // initalize SkewHeap;
		SkewHeap<int>* SH;
  };
  #endif
