/*
 * main.cpp
 * Liam Ormiston
 * 2-5-18
 * Main file for executing program
 */
#include "Execute.h"

int main(int argc, char const *argv[]) {
	Execute exec(argv[1]);
	exec.run();
	return 0;
};
