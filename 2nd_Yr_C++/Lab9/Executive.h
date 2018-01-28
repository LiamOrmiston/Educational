#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "PriorityQueue.h"
#include <string>
#include <iostream>
#include <fstream>

class Executive
{
public:
  Executive(const char* fileName); // constructor; it opens the indicated file and calls runSimulation.
  void runSimulation();
  template <typename T>
  void preview(PriorityQueue<T>& pq); // NOTE: The Priority Queue is passed by value!!!
private:
  std::ifstream file;
  std::string command;
  std::string name;
  int priority;
  int size;
};

#endif
