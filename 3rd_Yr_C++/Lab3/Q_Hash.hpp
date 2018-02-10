/*
 * Q_Hash.cpp
 * Liam Ormiston
 * 2-5-18
 * File for QHash class
 */
#include "Q_Hash.h"

// QHashtable constructor
template <typename T>
QHash<T>::QHash() {
	m_QHash = new LinkedList<int>* [m];
	// initializes each bucket with a linkedlist
	for (int i=0; i<m; i++) {
		m_QHash[i] = new LinkedList<int>;
	}
}
// QHashtable destructor
template<typename T>
QHash<T>::~QHash() {
	// destroys each linkedlist in every bucket
	for (int i=0; i<m; i++) {
		delete m_QHash[i];
	}
	// destroys the now empty qhashtable
	delete[] m_QHash;
}
// insertion method
template <typename T>
bool QHash<T>::qhash_insert(T value) {
	bool inserted = false;
	int i = 0;
	while ((inserted == false) && (i != k_max)) {
		if(m_QHash[h_i(value, i)]->isEmpty()) {
			inserted = true;
			n++; // number of elements
			return (m_QHash[h_i(value, i)]->insert(value));
		}
		else {
			i++;
		}
	}
	return inserted;
}
template <typename T>
int QHash<T>::h_i(int x, int i) {
	return ((x+(i*i))%m);
}
// delete method
template <typename T>
bool QHash<T>::qhash_delete(T value) {
	// figures out what bucket the value is in
	mod_num = value%7;
	// calls linkedlist erase to delete the value at the given bucket
	return (m_QHash[mod_num]->erase(value));
}
// find method
template <typename T>
bool QHash<T>::qhash_find(T value) {
	// figures out which bucket the value should be in
	mod_num = value%7;
	// calls linkedlist find method on the given bucket
	return (m_QHash[mod_num]->find(value));
}
// print method
template <typename T>
void QHash<T>::qhash_print() {
	std::cout << "Hash table with quadratic probing:" << std::endl;
	// goes through every bucket starting at 0
	for (int i=0; i<m; i++) {
		if(!m_QHash[i]->isEmpty()) {
			std::cout << i;
			std::cout << ": ";
			// calls linkedlist print method on every bucket
			m_QHash[i]->print();
		}
	}
	std::cout <<"\n";
}
template <typename T>
float QHash<T>::getLF() {
	return ((n*1.00)/(m*1.00));
}
