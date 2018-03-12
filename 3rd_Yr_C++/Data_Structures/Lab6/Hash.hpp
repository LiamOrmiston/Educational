/*
 * Hash.cpp
 * Liam Ormiston
 * 3-12-18
 * File for Hash class
 */
#include "Hash.h"

// Hashtable constructor
template <typename T>
Hash<T>::Hash(T value) {
  size = value;
  // creates an array with given size
  m_Hash = new LinkedList<int>* [value];
  // initializes each bucket with a linkedlist
  for (int i=0; i<size; i++) {
    m_Hash[i] = new LinkedList<int>;
  }
}
// Hashtable destructor
template<typename T>
Hash<T>::~Hash() {
  // destroys each linkedlist in every bucket
  for (int i=0; i<size; i++) {
    delete m_Hash[i];
  }
  // destroys the now empty hashtable
  delete[] m_Hash;
}
// insertion method
template <typename T>
bool Hash<T>::hash_insert(T value) {
  // figures out what bucket to place the value in
  mod_num = value%size;
  // calls the linkedlist insertion method on the given bucket
  return (m_Hash[mod_num]->insert(value));
}
// delete method
template <typename T>
bool Hash<T>::hash_delete(T value) {
  // figures out what bucket the value is in
  mod_num = value%7;
  // calls linkedlist erase to delete the value at the given bucket
  return (m_Hash[mod_num]->erase(value));
}
// find method
template <typename T>
bool Hash<T>::hash_find(T value) {
  // figures out which bucket the value should be in
  mod_num = value%size;
  // calls linkedlist find method on the given bucket
  return (m_Hash[mod_num]->find(value));
}
// print method
template <typename T>
void Hash<T>::hash_print() {
  std::cout << "Open Hashing:" << std::endl;
  // goes through every bucket starting at 0
  for (int i=0; i<size; i++) {
    if(!m_Hash[i]->isEmpty()) {
      std::cout << i;
      std::cout << ": ";
      // calls linkedlist print method on every bucket
      m_Hash[i]->print();
    }
  }
}
