/*
 * Hash.h
 * Liam Ormiston
 * 3-12-18
 * Header file for Hash class
 */
#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

template <typename T>
class Hash {
public:
  Hash(T value);
  ~Hash();
  bool hash_insert(T value);
  bool hash_delete(T value);
  bool hash_find(T value);
  void hash_print();
private:
  int size;
  int value;
  int mod_num;
  LinkedList<int>** m_Hash;
};
#include "Hash.hpp"
#endif
