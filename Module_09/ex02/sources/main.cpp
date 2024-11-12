#include <cmath>
#include <exception>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc <= 2) {
		std::cerr << "Invalid input! Valid input: "
					 "./PmergeMe [at least two positive "
					 "integers]"
				  << std::endl;
		return 1;
	}

	try {
		PmergeMe algorithm(argv);
		algorithm.sortVector();
		algorithm.sortList();
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
