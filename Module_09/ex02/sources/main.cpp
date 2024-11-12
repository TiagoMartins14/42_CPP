#include <cmath>
#include <ctime>
#include <exception>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc <= 2) {
		std::cerr << "Error: invalid input." << std::endl;
		return 1;
	}

	try {
		PmergeMe algorithm(argv);

		std::cout << "Before: ";
		algorithm.printVector();

		std::clock_t start = std::clock();
		algorithm.sortVector();
		std::clock_t end = std::clock();
		double vectorElapsedSeconds = double(end - start) / CLOCKS_PER_SEC;

		start = std::clock();
		algorithm.sortList();
		end = std::clock();
		double listElapsedSeconds = double(end - start) / CLOCKS_PER_SEC;

		std::cout << "After:  ";
		algorithm.printVector();

		std::cout << "Time to process a range of " << argc - 1
				  << " elements with std::vector : " << vectorElapsedSeconds
				  << " us" << std::endl;

		std::cout << "Time to process a range of " << argc - 1
				  << " elements with std::list   : " << listElapsedSeconds
				  << " us" << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
