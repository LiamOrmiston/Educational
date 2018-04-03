/*
 * Execute.h
 * Liam Ormiston
 * 4-12-18
 * Driver header file
 */
#ifndef EXECUTE_H
#define EXECUTE_H
#include <string>
#include <iostream>
#include <fstream>
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include "MaxHeap.h"
#include "MinHeap.h"

class Execute {
	public:
		Execute();
		~Execute();
		void run();

		float* BST_build_test(int size);
		float BST_deleteMax_test(BinarySearchTree<int>* BST_test, int* rand_arr, int size);
		float BST_deleteMin_test(BinarySearchTree<int>* BST_test, int* rand_arr, int size);
		void BST_tests(int size);

		float* MAX_build_test(int size);
		float MAX_deleteMax_test(MaxHeap* my_max_test, int* rand_arr, int size);
		float MAX_deleteMin_test(MaxHeap* my_max_test, int* rand_arr, int size);
		void MAX_tests(int size);

		float* MIN_build_test(int size);
		float MIN_deleteMax_test(MinHeap* my_min_test, int* rand_arr, int size);
		float MIN_deleteMin_test(MinHeap* my_min_test, int* rand_arr, int size);
		void MIN_tests(int size);


	private:
		int m = 1000000;
		BinarySearchTree<int>* BST;
		MaxHeap* my_max;
		MinHeap* my_min;
};
#endif
