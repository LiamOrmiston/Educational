/*
 * Q_Hash.h
 * Liam Ormiston
 * 3-12-18
 * Header file for QHash class
 */
#ifndef Q_HASH_H
#define Q_HASH_H
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

template <typename T>
class QHash {
	public:
		QHash(int m_value, int k_value);
		QHash(int m_value);
		~QHash();
		bool qhash_insert(T value);
		int h_i(int x, int i);
		bool qhash_delete(T value);
		bool qhash_find(T value);
		void qhash_print();
		float getLF();
	private:
		int m;
		int n = 0;
		int k_max;
		int value;
		int mod_num;
		LinkedList<int>** m_QHash;
};
#include "Q_Hash.hpp"
#endif
