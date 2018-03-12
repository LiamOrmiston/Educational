/*
 * Q_Hash.cpp
 * Liam Ormiston
 * 3-12-18
 * File for QHash class
 */
#include "Q_Hash.h"

// QHashtable constructor
template <typename T>
QHash<T>::QHash(int m_value, int k_value) {
	m = m_value;
	k_max = k_value;
	m_QHash = new LinkedList<int>* [m];
	// initializes each bucket with a linkedlist
	for (int i=0; i<m; i++) {
		m_QHash[i] = new LinkedList<int>;
	}
}
template <typename T>
QHash<T>::QHash(int m_value) {
	m = m_value;
	k_max = 4;
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
	// checks if value already exists
	if(!(qhash_find(value))) {
		// figures out what bucket to place the value in
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
	}
	return inserted;
}
// hash function
template <typename T>
int QHash<T>::h_i(int x, int i) {
	return ((x+(i*i))%m);
}
// delete method
template <typename T>
bool QHash<T>::qhash_delete(T value) {
	bool deleted = false;
	int i = 0;
	while ((deleted == false) && (i != k_max)) {
		if(m_QHash[h_i(value, i)]->find(value)) {
			deleted = true;
			n--; // number of elements
			return (m_QHash[h_i(value, i)]->erase(value));
		}
		else {
			i++;
		}
	}
	return deleted;
}
// find method
template <typename T>
bool QHash<T>::qhash_find(T value) {
	bool found = false;
	int i = 0;
	while ((found == false) && (i != k_max)) {
		if(m_QHash[h_i(value, i)]->find(value)) {
			found = true;
		}
		else {
			i++;
		}
	}
	return found;
}
// print method
template <typename T>
void QHash<T>::qhash_print() {
	std::cout << "Quadratic Probing:" << std::endl;
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
// get load factor method
template <typename T>
float QHash<T>::getLF() {
	return ((n*1.00)/(m*1.00));
}
