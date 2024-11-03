#include "PmergeMe.hpp"

#include <limits>

bool PmergeMe::isValidInput(const std::string &input) {
	for (size_t i = 0; i < input.length(); i++)
		if (!isdigit(input[i]) || !isspace(input[i])) return false;

	long number = std::atol(input.c_str());
	if (number > std::numeric_limits<int>::max() ||
		number < std::numeric_limits<int>::min())
		return false;

	return true;
}

void PmergeMe::createContainers(const char **argv) {
	for (size_t i = 1; argv[i]; i++) {
		if (!isValidInput(argv[i])) throw std::logic_error("Invalid input");

		_vectorContainer.push_back(std::atoi(argv[i]));
		_listContainer.push_back(std::atoi(argv[i]));
	}
}
