/*
 * main.cpp
 * Liam Ormiston
 * 4-24-18
 * Main file for executing program
 */
#include "ExecuteLeftist.h"
#include "ExecuteSkew.h"
#include <string.h>

int main(int argc, char const *argv[]) {
  // user did not provide a second argument
  if(argc != 2) {
    std::cout << "ERROR: Please execute either './Lab8 minleftist' or './Lab8 minskew'" << '\n';
  }
  // Will execute min-leftist heap
  else if(strcmp(argv[1],"minleftist")==0){
    ExecuteLeftist exec;
    exec.run();
  }
  // Will execute min-skew heap
  else if (strcmp(argv[1],"minskew")==0) {
    ExecuteSkew exec;
    exec.run();
  }
  // user provided incorrect second argument
  else {
    std::cout << "ERROR: Please execute either './Lab10 minleftist' or './Lab10 minskew'" << '\n';
  }
return 0;
};
