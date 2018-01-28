#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    if(argc>=2)
    {
        Executive exec(argv[1]);
        exec.runSimulation();
    }
    else
    {
        std::cout << "too many or few args!" << std::endl;
    }
    return 0;
}
