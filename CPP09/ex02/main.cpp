#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe pmerge;
	try {
		pmerge.parseInput(argc, argv);
		pmerge.sort();
		pmerge.display();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
