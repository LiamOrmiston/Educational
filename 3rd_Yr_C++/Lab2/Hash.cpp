/* Hash.cpp
 * Liam Ormiston
 * 1-29-18
 * Driver file for Hash functions
 */
 template <typename T>
Hash::Hash(T value) {
  // file.open("data.txt");
  //   file >> size;
  //   hash = new hash [size];
  //  while (file.good()) {
  //   file >> value;
  //   hash_insert(hash, value);
  // }
  // file.close();
}
template<typename T>
Hash::~Hash() {

}
template <typename T>
bool Hash::hash_insert(int myHash[], T value) {
  mod_num = value%6;
  myHash[mod_num].insert(value);
}
bool Hash::hash_delete(T value) {

}
bool Hash::hash_find(T value) {

}
void Hash::hash_print() {

}
