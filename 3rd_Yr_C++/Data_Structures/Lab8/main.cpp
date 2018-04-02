/*
 * main.cpp
 * Liam Ormiston
 * 4-2-18
 * Main file for executing program
 */
#include "Execute.h"
#include "ExecuteMax.h"
#include <string.h>

int main(int argc, char const *argv[]) {
  // user did not provide a second argument
  if(argc != 2) {
    std::cout << "ERROR: Please execute either './Lab8 minmax' or './Lab8 maxmin'" << '\n';
  }
  // Will execute Min-max heap
  else if(strcmp(argv[1],"minmax")==0){
    Execute exec;
    exec.run();
  }
  // Will execute Max-min heap
  else if (strcmp(argv[1],"maxmin")==0) {
    ExecuteMax exec;
    exec.run();
  }
  // user provided incorrect second argument
  else {
    std::cout << "ERROR: Please execute either './Lab8 minmax' or './Lab8 maxmin'" << '\n';
  }
return 0;
};
