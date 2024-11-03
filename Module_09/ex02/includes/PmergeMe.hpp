#pragma once
#include <cstdlib>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

class PmergeMe {
   private:
	char **_argv;
	std::vector<int> _vectorContainer;
	std::list<int> _listContainer;

	// General functions
	bool isValidInput(const std::string &input);
	void createContainers(const char **argv);

	// Vector functions

	// List functions
   public:
	PmergeMe(const std::string &input);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
};
