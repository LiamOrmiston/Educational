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
  if(strcmp(argv[1],"minmax")==0){
    Execute exec;
    exec.run();
  }
  else if (strcmp(argv[1],"maxmin")==0) {
    ExecuteMax exec;
    exec.run();
  }
  else {
    std::cout << "Please enter either 'minmax' or 'maxmin'" << '\n';
  }
return 0;
};
