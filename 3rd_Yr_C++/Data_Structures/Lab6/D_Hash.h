/*
 * D_Hash.h
 * Liam Ormiston
 * 3-12-18
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
		DHash(int m_value, int k_value, int p_value);
		DHash(int m_value);
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
		int m;
		int n = 0;
		int p;
		int k_max;
		int mod_num;
		LinkedList<int>** m_DHash;
};
#include "D_Hash.hpp"
#endif
