/*
* Execute.cpp
* Liam Ormiston
* 4-12-18
* Driver file for Hash methods
*/
#include "Execute.h"
#include <stdexcept>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

Execute::Execute() {
}
Execute::~Execute() {
	delete BST;
	delete my_max;
	delete my_min;
}
void Execute::run() {
	// std::cout << "BST TESTS:\n";
	// BST_tests(1*m);
	// BST_tests(2*m);
	// BST_tests(3*m);
	// BST_tests(4*m);
	// BST_tests(5*m);

	std::cout << "MAX HEAP TESTS:\n";
	MAX_tests(1*m);
	MAX_tests(2*m);
	MAX_tests(3*m);
	MAX_tests(4*m);
	MAX_tests(5*m);

	std::cout << "MIN HEAP TESTS:\n";
	MIN_tests(1*m);
	MIN_tests(2*m);
	MIN_tests(3*m);
	MIN_tests(4*m);
	MIN_tests(5*m);
}

/* ----------------------------------------------------------
BINARY SEARCH TREE TEST
---------------------------------------------------------- */

void Execute::BST_tests(int size) {
	float *myArr = new float[3];
	myArr = BST_build_test(size);

	printf("Build of %d took %f seconds\n", size, (float)myArr[0]/CLOCKS_PER_SEC);
	printf("Delete Max of %d took %f seconds\n", size, (float)myArr[1]/CLOCKS_PER_SEC);
	printf("Delete Min of %d took %f seconds\n", size, (float)myArr[2]/CLOCKS_PER_SEC);
}
float* Execute::BST_build_test(int size) {
	// new seed
	srand(time(NULL));
	clock_t t;
	float *myArr = new float[3];
	float build_avg = 0.00;
	float deleteMax_avg = 0.00;
	float deleteMin_avg = 0.00;
	for(int i=0; i < 5; i++) {
		// start clock
		t = clock();
		// build and insert
		BinarySearchTree<int>* BST_test = new BinarySearchTree<int>();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			BST_test->add(num);
		}
		// end clock
		t = clock() - t;
		build_avg = build_avg + t;

		BinarySearchTree<int>* BST_min_test = new BinarySearchTree<int>();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			BST_min_test->add(num);
		}
		BinarySearchTree<int>* BST_max_test = new BinarySearchTree<int>();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			BST_max_test->add(num);
		}

		deleteMax_avg = deleteMax_avg + BST_deleteMax_test(BST_max_test, size);
		deleteMin_avg = deleteMin_avg + BST_deleteMin_test(BST_min_test, size);

		delete BST_test;
		delete BST_max_test;
		delete BST_min_test;
	}
	build_avg = build_avg/5;
	deleteMax_avg = deleteMax_avg/5;
	deleteMin_avg = deleteMin_avg/5;

	myArr[0] = build_avg;
	myArr[1] = deleteMax_avg;
	myArr[2] = deleteMin_avg;
	return myArr;
}
float Execute::BST_deleteMax_test(BinarySearchTree<int>* BST_test, int size) {
	clock_t t;
	float deleteMax = 0.00;

	for (int i = 0; i < (size); i++) {
		// start clock
		t = clock();
		if (BST_test->deleteMax()) {
			// end clock
			deleteMax = deleteMax + (clock() - t);
		}
	}
	return deleteMax;
}
float Execute::BST_deleteMin_test(BinarySearchTree<int>* BST_test, int size) {
	clock_t t;
	float deleteMin = 0.00;

	for (int i = 0; i < (size); i++) {
		// start clock
		t = clock();
		if (BST_test->deleteMin()) {
			// end clock
			deleteMin = deleteMin + (clock() - t);
		}
	}
	return deleteMin;
}

/* ----------------------------------------------------------
MAX HEAP TEST
---------------------------------------------------------- */

void Execute::MAX_tests(int size) {
	float *myArr = new float[3];
	std::cout << "calling build test" << '\n';
	myArr = MAX_build_test(size);

	printf("Build of %d took %f seconds\n", size, (float)myArr[0]/CLOCKS_PER_SEC);
	printf("Delete Max of %d took %f seconds\n", size, (float)myArr[1]/CLOCKS_PER_SEC);
	printf("Delete Min of %d took %f seconds\n", size, (float)myArr[2]/CLOCKS_PER_SEC);
}
float* Execute::MAX_build_test(int size) {
	// new seed
	srand(time(NULL));
	clock_t t;
	float *myArr = new float[3];
	float build_avg = 0.00;
	float deleteMax_avg = 0.00;
	float deleteMin_avg = 0.00;
	for(int i=0; i < 5; i++) {
		std::cout << "starting clock" << '\n';
		// start clock
		t = clock();
		// build and insert
		std::cout << "building and inserting" << '\n';
		MaxHeap* MAX_test = new MaxHeap();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			MAX_test->insert(num);
		}
		std::cout << "done building. stopping clock" << '\n';
		// end clock
		t = clock() - t;
		build_avg = build_avg + t;
 std::cout << "create heaps to test delete" << '\n';
		MaxHeap* MAX_max_test = new MaxHeap();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			MAX_max_test->insert(num);
		}
		MaxHeap* MAX_min_test = new MaxHeap();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			MAX_min_test->insert(num);
		}

		// deleteMax_avg = deleteMax_avg + MAX_deleteMax_test(MAX_max_test, size);
		// deleteMin_avg = deleteMin_avg + MAX_deleteMin_test(MAX_min_test, size);
std::cout << "deleting previously created heaps" << '\n';
		delete MAX_test;
		delete MAX_max_test;
		delete MAX_min_test;
		std::cout << "done" << '\n';
	}
	build_avg = build_avg/5;
	deleteMax_avg = deleteMax_avg/5;
	deleteMin_avg = deleteMin_avg/5;

	myArr[0] = build_avg;
	myArr[1] = deleteMax_avg;
	myArr[2] = deleteMin_avg;
	return myArr;
}
float Execute::MAX_deleteMax_test(MaxHeap* MAX_test, int size) {
	clock_t t;
	float deleteMax = 0.00;

	for (int i = 0; i < (size); i++) {
		// start clock
		t = clock();
		MAX_test->deleteMax();
		// end clock
		deleteMax = deleteMax + (clock() - t);
	}
	return deleteMax;
}
float Execute::MAX_deleteMin_test(MaxHeap* MAX_test, int size) {
	clock_t t;
	float deleteMin = 0.00;

	for (int i = 0; i < (size); i++) {
		// start clock
		t = clock();
		MAX_test->deleteMin();
		// end clock
		deleteMin = deleteMin + (clock() - t);
	}
	return deleteMin;
}

/* ----------------------------------------------------------
MIN HEAP TEST
---------------------------------------------------------- */

void Execute::MIN_tests(int size) {
	float *myArr = new float[3];
	myArr = MIN_build_test(size);

	printf("Build of %d took %f seconds\n", size, (float)myArr[0]/CLOCKS_PER_SEC);
	printf("Delete Max of %d took %f seconds\n", size, (float)myArr[1]/CLOCKS_PER_SEC);
	printf("Delete Min of %d took %f seconds\n", size, (float)myArr[2]/CLOCKS_PER_SEC);
}
float* Execute::MIN_build_test(int size) {
	clock_t t;
	// new seed
	srand(time(NULL));
	float *myArr = new float[3];
	float build_avg = 0.00;
	float deleteMax_avg = 0.00;
	float deleteMin_avg = 0.00;
	for(int i=0; i < 5; i++) {
		// start clock
		t = clock();
		// build and insert
		MinHeap* MIN_test = new MinHeap();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			MIN_test->insert(num);
		}
		// end clock
		t = clock() - t;
		build_avg = build_avg + t;

		MinHeap* MIN_max_test = new MinHeap();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			MIN_max_test->insert(num);
		}
		MinHeap* MIN_min_test = new MinHeap();
		for (int i = 0; i < (size); i++) {
			int num = rand();
			MIN_min_test->insert(num);
		}

		deleteMax_avg = deleteMax_avg + MIN_deleteMax_test(MIN_max_test, size);
		deleteMin_avg = deleteMin_avg + MIN_deleteMin_test(MIN_min_test, size);

		delete MIN_test;
		delete MIN_max_test;
		delete MIN_min_test;
	}
	build_avg = build_avg/5;
	deleteMax_avg = deleteMax_avg/5;
	deleteMin_avg = deleteMin_avg/5;

	myArr[0] = build_avg;
	myArr[1] = deleteMax_avg;
	myArr[2] = deleteMin_avg;
	return myArr;
}
float Execute::MIN_deleteMax_test(MinHeap* MIN_test, int size) {
	clock_t t;
	float deleteMax = 0.00;

	for (int i = 0; i < (size); i++) {
		// start clock
		t = clock();
		MIN_test->deleteMax();
		// end clock
		deleteMax = deleteMax + (clock() - t);
	}
	return deleteMax;
}
float Execute::MIN_deleteMin_test(MinHeap* MIN_test, int size) {
	clock_t t;
	float deleteMin = 0.00;

	for (int i = 0; i < (size); i++) {
		// start clock
		t = clock();
		MIN_test->deleteMin();
		// end clock
		deleteMin = deleteMin + (clock() - t);
	}
	return deleteMin;
}
