/*
 * D_Hash.h
 * Liam Ormiston
 * 2-5-18
 * Header file for DHash class
 */
#ifndef D_HASH_H
#define D_HASH_H
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

template <typename T>
class DHash {
	public:
		DHash();
		~DHash();
		bool dhash_insert(T value);
		int h_k(int x, int k);
		int h(int x);
		int h_plus(int x);
		bool dhash_delete(T value);
		bool dhash_find(T value);
		void dhash_print();
		float getLF();
	private:
		int value;
		int m = 53;
		int n = 0;
		int p = 13;
		int k_max = 10;
		int mod_num;
		LinkedList<int>** m_DHash;
};
#include "D_Hash.hpp"
#endif
