/*
 * D_Hash.cpp
 * Liam Ormiston
 * 2-5-18
 * File for DHash class
 */
#include "D_Hash.h"

// DHashtable constructor
template <typename T>
DHash<T>::DHash() {
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
	// figures out what bucket to place the value in
	bool inserted = false;
	int k = 0;
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
	return (inserted);
}
template <typename T>
int DHash<T>::h_k(int x, int k) {
	return ((h(x)+(k*(h_plus(x))))%m);
}
template <typename T>
int DHash<T>::h(int x) {
	return(x%m);
}
template <typename T>
int DHash<T>::h_plus(int x) {
	return (p-(x%p));
}
// delete method
template <typename T>
bool DHash<T>::dhash_delete(T value) {
	// figures out what bucket the value is in
	mod_num = value%7;
	// calls linkedlist erase to delete the value at the given bucket
	return (m_DHash[mod_num]->erase(value));
}
// find method
template <typename T>
bool DHash<T>::dhash_find(T value) {
	// figures out which bucket the value should be in
	mod_num = value%7;
	// calls linkedlist find method on the given bucket
	return (m_DHash[mod_num]->find(value));
}
// print method
template <typename T>
void DHash<T>::dhash_print() {
	std::cout << "Hash table with double hashing:" << std::endl;
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
template <typename T>
long DHash<T>::getLF() {
	return ((n*1.00)/(m*1.00));
}
