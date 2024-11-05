#include "PmergeMe.hpp"

#include <iterator>
#include <limits>

PmergeMe::PmergeMe(char **argv) : _argv(argv) { createContainers(_argv); }

PmergeMe::PmergeMe(const PmergeMe &other)
    : _argv(other._argv), _vectorContainer(other._vectorContainer),
      _listContainer(other._listContainer) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    _argv = other._argv;
    _vectorContainer = other._vectorContainer;
    _listContainer = other._listContainer;
  }

  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::createContainers(char **argv) {
  for (size_t i = 1; argv[i]; i++) {
    if (!isValidInput(argv[i]))
      throw std::logic_error("Invalid input");

    _vectorContainer.push_back(std::atoi(argv[i]));
    _listContainer.push_back(std::atoi(argv[i]));
  }
}

bool PmergeMe::isValidInput(const std::string &input) {
  for (size_t i = 0; i < input.length(); i++)
    if (!isdigit(input[i]) && !isspace(input[i]))
      return false;

  long number = std::atol(input.c_str());
  if (number > std::numeric_limits<int>::max() ||
      number < std::numeric_limits<int>::min())
    return false;

  return true;
}

void PmergeMe::vectorOrderPairs() {
  for (size_t i = 0; i < _vectorContainer.size(); i += 2) {
    if (i < _vectorContainer.size() - 1) {
      if (_vectorContainer[i] > _vectorContainer[i + 1]) {
        int temp = _vectorContainer[i];
        _vectorContainer[i] = _vectorContainer[i + 1];
        _vectorContainer[i + 1] = temp;
      }
    }
  }
}

void PmergeMe::listOrderPairs() {
  std::list<int>::iterator it;
  for (it = _listContainer.begin(); it != _listContainer.end();) {
    int num1 = *it;
    it++;
    if (it != _listContainer.end()) {
      int num2 = *it;
      if (num1 > num2) {
        *it = num1;
        it--;
        *it = num2;
        it++;
      }
      it++;
    }
  }
}

void PmergeMe::vectorPutPairsInAscendingOrder() {}

void PmergeMe::listPutPairsInAscendingOrder() {}

// TEST FUNCTIONS
void PmergeMe::printVector() {
  std::cout << "Elements in vector: ";
  for (size_t i = 0; i < _vectorContainer.size(); ++i) {
    std::cout << _vectorContainer[i] << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printList() {
  std::cout << "Elements in list: ";
  for (std::list<int>::const_iterator it = _listContainer.begin();
       it != _listContainer.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

// TESTE FUNCTIONS
