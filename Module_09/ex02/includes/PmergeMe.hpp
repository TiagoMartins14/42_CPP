#pragma once
#include <unistd.h>

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

class PmergeMe {
   private:
	char **_argv;
	std::vector<int> _vectorContainer;
	std::vector<int> _vectorAidContainer;
	std::list<int> _listContainer;
	std::list<int> _listAidContainer;

	// General functions
	bool isValidInput(const std::string &input);
	void createContainers(char **argv);
	long getJacobsthalNumber(size_t index);
	long findMiddleValue(long minIndex, long maxIndex);

	// Vector functions
	void vectorOrderPairs();
	void vectorPutPairsInAscendingOrder();
	void vectorSplitContainer();
	void vectorInsertNumbers();

	// List functions
	void listOrderPairs();
	void listPutPairsInAscendingOrder();
	void listSplitContainer();
	int getNumAtIndex(long index, std::list<int> container);
	void insertNumAtIndex(int num, long index);
	void listInsertNumbers();

	// TEST FUNCTIONS
	void printVector();
	void printVectorAid();

	void printList();
	void printListAid();

   public:
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void sortVector();
	void sortList();
};
