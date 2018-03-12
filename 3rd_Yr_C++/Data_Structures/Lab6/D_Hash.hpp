/*
 * D_Hash.cpp
 * Liam Ormiston
 * 3-12-18
 * File for DHash class
 */
#include "D_Hash.h"

// DHashtable constructor
template <typename T>
DHash<T>::DHash(int m_value, int k_value, int p_value) {
	m = m_value;
	p = p_value;
	k_max = k_value;
	m_DHash = new LinkedList<int>* [m];
	// initializes each bucket with a linkedlist
	for (int i=0; i<m; i++) {
		m_DHash[i] = new LinkedList<int>;
	}
}
template <typename T>
DHash<T>::DHash(int m_value) {
	m = m_value;
	p = 5;
	k_max = 4;
	m_DHash = new LinkedList<int>* [m];
	// initializes each bucket with a linkedlist
	for (int i=0; i<m; i++) {
		m_DHash[i] = new LinkedList<int>;
	}
}
// DHashtable destructor
template<typename T>
DHash<T>::~DHash() {
	// destroys each linkedlist in every bucket
	for (int i=0; i<m; i++) {
		delete m_DHash[i];
	}
	// destroys the now empty dhashtable
	delete[] m_DHash;
}
// insertion method
template <typename T>
bool DHash<T>::dhash_insert(T value) {
	bool inserted = false;
	int k = 0;
	// figures out what bucket to place the value in
	if(!(dhash_find(value))) {
		// checks if value already exists
		while (inserted == false && k != k_max) {
			if(m_DHash[h_k(value, k)]->isEmpty()) {
				inserted = true;
				n++;
				return (m_DHash[h_k(value, k)]->insert(value));
			}
			else {
				k++;
			}
		}
	}
	return (inserted);
}
// main hash function
template <typename T>
int DHash<T>::h_k(int x, int k) {
	return ((h(x)+(k*(h_plus(x))))%m);
}
// hash function always executes
template <typename T>
int DHash<T>::h(int x) {
	return(x%m);
}
// hash function executed only when first bucket is full
template <typename T>
int DHash<T>::h_plus(int x) {
	return (p-(x%p));
}
// delete method
template <typename T>
bool DHash<T>::dhash_delete(T value) {
	bool deleted = false;
	int k = 0;
	while (deleted == false && k != k_max) {
		if(m_DHash[h_k(value, k)]->find(value)) {
			deleted = true;
			n--;
			return (m_DHash[h_k(value, k)]->erase(value));
		}
		else {
			k++;
		}
	}
	return (deleted);
}
// find method
template <typename T>
bool DHash<T>::dhash_find(T value) {
	bool found = false;
	int k = 0;
	while (found == false && k != k_max) {
		if(m_DHash[h_k(value, k)]->find(value)) {
			found = true;
		}
		else {
			k++;
		}
	}
	return (found);
}
// print method
template <typename T>
void DHash<T>::dhash_print() {
	std::cout << "Double Hashing:" << std::endl;
	// goes through every bucket starting at 0
	for (int i=0; i<m; i++) {
		if(!m_DHash[i]->isEmpty()) {
			std::cout << i;
			std::cout << ": ";
			// calls linkedlist print method on every bucket
			m_DHash[i]->print();
		}
	}
	std::cout <<"\n";
}
// get load factor method
template <typename T>
float DHash<T>::getLF() {
	return ((n*1.00)/(m*1.00));
}
