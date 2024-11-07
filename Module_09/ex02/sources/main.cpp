#include <cmath>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc >= 2) {
		PmergeMe algorithm(argv);
		std::cout << " ----- Original containers ----- " << std::endl;
		algorithm.printVector();
		algorithm.printList();
		std::cout << std::endl;

		algorithm.vectorOrderPairs();
		algorithm.listOrderPairs();

		std::cout << " ----- Ordered pairs ----- " << std::endl;
		algorithm.printVector();
		algorithm.printList();
		std::cout << std::endl;

		algorithm.vectorPutPairsInAscendingOrder();
		algorithm.listPutPairsInAscendingOrder();

		std::cout << " ----- Pairs in ascending order ----- " << std::endl;
		algorithm.printVector();
		algorithm.printList();
		std::cout << std::endl;

		algorithm.vectorSplitContainer();
		algorithm.listSplitContainer();

		std::cout << " ----- Split containers ----- " << std::endl;
		algorithm.printVector();
		algorithm.printVectorAid();
		std::cout << std::endl;
		algorithm.printList();
		algorithm.printListAid();
	}
}
