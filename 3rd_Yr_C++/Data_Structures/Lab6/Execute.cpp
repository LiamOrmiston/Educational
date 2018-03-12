/*
 * Execute.cpp
 * Liam Ormiston
 * 3-12-18
 * Driver file for Hash methods
 */
#include "Execute.h"
#include <stdexcept>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

Execute::Execute() {
	choice = 0;
}
Execute::~Execute() {
	delete QH;
	delete DH;
	delete H;
}
void Execute::run() {
	while (choice != 3) {
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "Please choose one of the following commands:" << std::endl;
		std::cout << "1 - Test HashTables" << std::endl;
		std::cout << "2 - Performance Comparison" << std::endl;
		std::cout << "3 - Exit" << std::endl;
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
	std::cout << "What is the table size?" << std::endl;
	std::cin >> input;
	try{
		value = std::stoi(input);
		file.open("data.txt");
		QH = new QHash<int>(value);
		DH = new DHash<int>(value);
		H = new Hash<int>(value);
		while (file.good()) {
			file >> value;
			// TODO: Possibly need to have the insert function check for duplicates to
			// optimize speed.
			if (!QH->qhash_find(value)) {
				QH->qhash_insert(value);
			}
			if (!DH->dhash_find(value)) {
				DH->dhash_insert(value);
			}
			if (!H->hash_find(value)) {
				H->hash_insert(value);
			}
		}
		file.close();
		H->hash_print();
		QH->qhash_print();
		DH->dhash_print();

	}
	catch(const std::invalid_argument e) {
		std::cout << "invalid input." << std::endl;
	}
	catch(const std::out_of_range e) {
		std::cout << "invalid input." << std::endl;
	}
}

void Execute::choice_2() {
	std::cout << "Quadratic Tests:\n";
	Q_tests(0.1);
	Q_tests(0.2);
	Q_tests(0.3);
	Q_tests(0.4);
	Q_tests(0.5);

	std::cout << "Double Tests:\n";
	D_tests(0.1);
	D_tests(0.2);
	D_tests(0.3);
	D_tests(0.4);
	D_tests(0.5);

	std::cout << "Open Tests:\n";
	H_tests(0.1);
	H_tests(0.2);
	H_tests(0.3);
	H_tests(0.4);
	H_tests(0.5);
}

/* ----------------------------------------------------------
QUADRATIC HASH TEST
---------------------------------------------------------- */

void Execute::Q_tests(float size) {
	float *myArr = new float[3];
	int m_size = (size*1000003);
	myArr = Q_build_test(size);

	printf("Build of %d took %f seconds\n", m_size, (float)myArr[0]/CLOCKS_PER_SEC);
	printf("Find of %d took %f seconds\n", m_size, (float)myArr[1]/CLOCKS_PER_SEC);
	printf("Not found of %d took %f seconds\n", m_size, (float)myArr[2]/CLOCKS_PER_SEC);
}
float* Execute::Q_build_test(float size) {
	int m = 1000003;
	int m_size = (size*m);
	int k = 20;
	// new seed
	srand(time(NULL));
	clock_t t;
	float *myArr = new float[3];
	float build_avg = 0.00;
	float found_avg = 0.00;
	float not_found_avg = 0.00;
	for(int i=0; i < 5; i++) {
		// start clock
		t = clock();
		// build and insert
		QHash<int>* QH_test = new QHash<int>(m, k);
		for (int i = 0; i < (size*m); i++) {
			int num = rand() % (5*m);
			QH_test->qhash_insert(num);
		}
		// end clock
		t = clock() - t;
		build_avg = build_avg + t;

		// new seed
		srand(time(NULL));
		int* rand_arr = new int[m_size];
		for (int i = 0; i < (m_size); i++) {
			int num = rand() % (5*m);
			rand_arr[i] = num;
		}

		found_avg = found_avg + Q_found_test(QH_test, rand_arr, m_size);
		not_found_avg = not_found_avg + Q_not_found_test(QH_test, rand_arr, m_size);

		delete QH_test;
	}
	build_avg = build_avg/5;
	found_avg = found_avg/5;
	not_found_avg = not_found_avg/5;

	myArr[0] = build_avg;
	myArr[1] = found_avg;
	myArr[2] = not_found_avg;
	return myArr;
}
float Execute::Q_found_test(QHash<int>* QH_test, int* rand_arr, float m_size) {
	clock_t t;
	float found = 0.00;

	for (int i = 0; i < (m_size); i++) {
		// start clock
		t = clock();
		if (QH_test->qhash_find(rand_arr[i])) {
			// end clock
			found = found + (clock() - t);
		}
	}
	return found;
}
float Execute::Q_not_found_test(QHash<int>* QH_test, int* rand_arr, float m_size) {
	clock_t t;
	float not_found = 0.00;

	for (int i = 0; i < (m_size); i++) {
		// start clock
		t = clock();
		if (!QH_test->qhash_find(rand_arr[i])) {
			// end clock
			not_found = not_found + (clock() - t);
		}
	}
	return not_found;
}

/* ----------------------------------------------------------
DOUBLE HASH TEST
---------------------------------------------------------- */

void Execute::D_tests(float size) {
	float *myArr = new float[3];
	int m_size = (size*1000003);
	myArr = D_build_test(size);

	printf("Build of %d took %f seconds\n", m_size, (float)myArr[0]/CLOCKS_PER_SEC);
	printf("Find of %d took %f seconds\n", m_size, (float)myArr[1]/CLOCKS_PER_SEC);
	printf("Not found of %d took %f seconds\n", m_size, (float)myArr[2]/CLOCKS_PER_SEC);
}
float* Execute::D_build_test(float size) {
	int m = 1000003;
	int m_size = (size*m);
	int k = 20;
	int p = 997;
	// new seed
	srand(time(NULL));
	clock_t t;
	float *myArr = new float[3];
	float build_avg = 0.00;
	float found_avg = 0.00;
	float not_found_avg = 0.00;
	for(int i=0; i < 5; i++) {
		// start clock
		t = clock();
		// build and insert
		DHash<int>* DH_test = new DHash<int>(m, k, p);
		for (int i = 0; i < (size*m); i++) {
			int num = rand() % (5*m);
			DH_test->dhash_insert(num);
		}
		// end clock
		t = clock() - t;
		build_avg = build_avg + t;

		// new seed
		srand(time(NULL));
		int* rand_arr = new int[m_size];
		for (int i = 0; i < (m_size); i++) {
			int num = rand() % (5*m);
			rand_arr[i] = num;
		}

		found_avg = found_avg + D_found_test(DH_test, rand_arr, m_size);
		not_found_avg = not_found_avg + D_not_found_test(DH_test, rand_arr, m_size);

		delete DH_test;
	}
	build_avg = build_avg/5;
	found_avg = found_avg/5;
	not_found_avg = not_found_avg/5;

	myArr[0] = build_avg;
	myArr[1] = found_avg;
	myArr[2] = not_found_avg;
	return myArr;
}
float Execute::D_found_test(DHash<int>* DH_test, int* rand_arr, float m_size) {
	clock_t t;
	float found = 0.00;

	for (int i = 0; i < (m_size); i++) {
		// start clock
		t = clock();
		if (DH_test->dhash_find(rand_arr[i])) {
			// end clock
			found = found + (clock() - t);
		}
	}
	return found;
}
float Execute::D_not_found_test(DHash<int>* DH_test, int* rand_arr, float m_size) {
	clock_t t;
	float not_found = 0.00;

	for (int i = 0; i < (m_size); i++) {
		// start clock
		t = clock();
		if (!DH_test->dhash_find(rand_arr[i])) {
			// end clock
			not_found = not_found + (clock() - t);
		}
	}
	return not_found;
}

/* ----------------------------------------------------------
OPEN HASH TEST
---------------------------------------------------------- */

void Execute::H_tests(float size) {
	float *myArr = new float[3];
	int m_size = (size*1000003);
	myArr = H_build_test(size);

	printf("Build of %d took %f seconds\n", m_size, (float)myArr[0]/CLOCKS_PER_SEC);
	printf("Find of %d took %f seconds\n", m_size, (float)myArr[1]/CLOCKS_PER_SEC);
	printf("Not found of %d took %f seconds\n", m_size, (float)myArr[2]/CLOCKS_PER_SEC);
}
float* Execute::H_build_test(float size) {
	int m = 1000003;
	int m_size = (size*m);
	clock_t t;
	// new seed
	srand(time(NULL));
	float *myArr = new float[3];
	float build_avg = 0.00;
	float found_avg = 0.00;
	float not_found_avg = 0.00;
	for(int i=0; i < 5; i++) {
		// start clock
		t = clock();
		// build and insert
		Hash<int>* H_test = new Hash<int>(m);
		for (int i = 0; i < (size*m); i++) {
			int num = rand() % (5*m);
			H_test->hash_insert(num);
		}
		// end clock
		t = clock() - t;
		build_avg = build_avg + t;

		// new seed
		srand(time(NULL));
		int* rand_arr = new int[m_size];
		for (int i = 0; i < (m_size); i++) {
			int num = rand() % (5*m);
			rand_arr[i] = num;
		}

		found_avg = found_avg + H_found_test(H_test, rand_arr, m_size);
		not_found_avg = not_found_avg + H_not_found_test(H_test, rand_arr, m_size);

		delete H_test;
	}
	build_avg = build_avg/5;
	found_avg = found_avg/5;
	not_found_avg = not_found_avg/5;

	myArr[0] = build_avg;
	myArr[1] = found_avg;
	myArr[2] = not_found_avg;
	return myArr;
}
float Execute::H_found_test(Hash<int>* H_test, int* rand_arr, float m_size) {
	clock_t t;
	float found = 0.00;

	for (int i = 0; i < (m_size); i++) {
		// start clock
		t = clock();
		if (H_test->hash_find(rand_arr[i])) {
			// end clock
			found = found + (clock() - t);
		}
	}
	return found;
}
float Execute::H_not_found_test(Hash<int>* H_test, int* rand_arr, float m_size) {
	clock_t t;
	float not_found = 0.00;

	for (int i = 0; i < (m_size); i++) {
		// start clock
		t = clock();
		if (!H_test->hash_find(rand_arr[i])) {
			// end clock
			not_found = not_found + (clock() - t);
		}
	}
	return not_found;
}
