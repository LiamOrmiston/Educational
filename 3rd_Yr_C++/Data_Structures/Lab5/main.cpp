#include "Execute.h"

int main(int argc, char const *argv[]) {
	Execute exec("data.txt");
	exec.run();
	return 0;
};
