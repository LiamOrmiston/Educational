/* Hash.h
 * Liam Ormiston
 * 1-29-18
 * Driver file
 */
#ifndef HASH_H
#define HASH_H
#include "LinkedList.h"
class Hash {
public:
  Hash();
  ~Hash();
  bool hash_insert(int myHash[], T value);
  bool hash_delete(T value);
  bool hash_find(T value);
  void hash_print();
private:
  int size;
  int value;
  LinkedList<int> hash[];
  int mod_num;
};
#endif
