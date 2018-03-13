/*
 * Execute.h
 * Liam Ormiston
 * 3-12-18
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
#include "Hash.h"

class Execute {
	public:
		Execute();
		~Execute();
		void run();
		void choice_1();
		void choice_2();

		float* Q_build_test(float size);
		float Q_found_test(QHash<int>* QH_test, int* rand_arr, float m_size);
		float Q_not_found_test(QHash<int>* QH_test, int* rand_arr, float m_size);
		void Q_tests(float size);

		float* D_build_test(float size);
		float D_found_test(DHash<int>* DH_test, int* rand_arr, float m_size);
		float D_not_found_test(DHash<int>* DH_test, int* rand_arr, float m_size);
		void D_tests(float size);

		float* H_build_test(float size);
		float H_found_test(Hash<int>* H_test, int* rand_arr, float m_size);
		float H_not_found_test(Hash<int>* H_test, int* rand_arr, float m_size);
		void H_tests(float size);

		
		// void D_build_test();
		// void H_build_test();
	private:
		std::ifstream file;
		std::string input;
		int value;
		int choice;
		DHash<int>* DH;
		QHash<int>* QH;
		Hash<int>* H;
		LinkedList<int> L;
};
#endif
