#include "Execute.h"

int main(int argc, char const *argv[]) {
	if(argv[1]){
		Execute exec(argv[1]);
		exec.run();
	}
	else {
		std::cout<<"Please include a file name\n";
		std::cout << "Either: data.txt, skew_tree.txt, or complete_tree.txt\n";
	}
	return 0;
};
