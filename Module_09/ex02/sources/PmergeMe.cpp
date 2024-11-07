#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) : _argv(argv) { createContainers(_argv); }

PmergeMe::PmergeMe(const PmergeMe &other)
	: _argv(other._argv),
	  _vectorContainer(other._vectorContainer),
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

// General functions
bool PmergeMe::isValidInput(const std::string &input) {
	for (size_t i = 0; i < input.length(); i++)
		if (!isdigit(input[i]) && !isspace(input[i])) return false;

	long number = std::atol(input.c_str());
	if (number > std::numeric_limits<int>::max() ||
		number < std::numeric_limits<int>::min())
		return false;

	return true;
}

void PmergeMe::createContainers(char **argv) {
	for (size_t i = 1; argv[i]; i++) {
		if (!isValidInput(argv[i])) throw std::logic_error("Invalid input");

		_vectorContainer.push_back(std::atoi(argv[i]));
		_listContainer.push_back(std::atoi(argv[i]));
	}
}

long PmergeMe::getJacobsthalNumber(size_t index) {
	long a = 0;
	long b = 1;
	long number = 0;

	while (index != 0) {
		number = b + (2 * a);
		a = b;
		b = number;
		index--;
	}

	return number;
}

long PmergeMe::findMiddleValue(long max) { return max / 2; }

// Vector functions
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

void PmergeMe::vectorPutPairsInAscendingOrder() {
	size_t i = 0;
	size_t stop;
	if (_vectorContainer.size() % 2 == 0)
		stop = _vectorContainer.size() - 2;
	else
		stop = _vectorContainer.size() - 3;

	while (i != stop) {
		if (_vectorContainer[i + 1] > _vectorContainer[i + 3]) {
			int mainChainValue = _vectorContainer[i + 1];
			int secondaryChainValue = _vectorContainer[i];
			_vectorContainer[i] = _vectorContainer[i + 2];
			_vectorContainer[i + 2] = secondaryChainValue;
			_vectorContainer[i + 1] = _vectorContainer[i + 3];
			_vectorContainer[i + 3] = mainChainValue;
			i = 0;
		} else
			i += 2;
	}
}

void PmergeMe::vectorSplitContainer() {
	std::vector<int>::iterator it = _vectorContainer.begin();

	for (size_t i = 0; i < _vectorContainer.size(); i++) {
		if (i == _vectorContainer.size() - 1) break;
		_vectorAidContainer.push_back(_vectorContainer[i]);
		_vectorContainer.erase(it);
		it++;
	}
}

void PmergeMe::vectorInsertNumbers() {
	size_t counter = 2;
	size_t i;
	long jacobsthalNumber = getJacobsthalNumber(counter);
	long savedNumber = jacobsthalNumber;
	long maxNumber = static_cast<long>(_vectorContainer.size());

	_vectorContainer.insert(_vectorContainer.begin(), _vectorAidContainer[0]);

	while (jacobsthalNumber < maxNumber) {
		long mid = findMiddleValue(jacobsthalNumber);
		if (_vectorAidContainer[jacobsthalNumber] > mid)

		// TODO: recursiva para ir partindo a meio ate encontrar o sweet spot
	}
}

// List functions
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

void PmergeMe::listPutPairsInAscendingOrder() {
	if (_listContainer.size() < 4) return;

	std::list<int>::iterator it = _listContainer.begin();
	std::list<int>::iterator stopIt = _listContainer.end();
	if (_listContainer.size() % 2 == 0)
		std::advance(stopIt, -2);
	else
		std::advance(stopIt, -3);

	while (it != stopIt) {
		int secondaryChainNum1 = *it;
		it++;
		int mainChainNum1 = *it;
		it++;
		int secondaryChainNum2 = *it;
		it++;
		int mainChainNum2 = *it;
		if (mainChainNum1 > mainChainNum2) {
			*it = mainChainNum1;
			it--;
			*it = secondaryChainNum1;
			it--;
			*it = mainChainNum2;
			it--;
			*it = secondaryChainNum2;
			it = _listContainer.begin();
		} else {
			it--;
		}
	}
}

void PmergeMe::listSplitContainer() {
	std::list<int>::iterator it = _listContainer.begin();

	for (size_t i = 0; i < _listContainer.size(); i++) {
		if (i == _listContainer.size() - 1) break;
		_listAidContainer.push_back(*it);
		std::list<int>::iterator tempIt = it;
		it++;
		it++;
		_listContainer.erase(tempIt);
	}
}

// TEST FUNCTIONS
void PmergeMe::printVector() {
	std::cout << "Elements in vector: ";
	for (size_t i = 0; i < _vectorContainer.size(); ++i) {
		if (i % 2 == 1)
			std::cout << "[" << _vectorContainer[i] << "] ";
		else
			std::cout << _vectorContainer[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVectorAid() {
	std::cout << "Elements in vectorAid: ";
	for (size_t i = 0; i < _vectorAidContainer.size(); ++i) {
		if (i % 2 == 1)
			std::cout << "[" << _vectorAidContainer[i] << "] ";
		else
			std::cout << _vectorAidContainer[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList() {
	int index = 0;
	std::cout << "Elements in list:   ";
	for (std::list<int>::const_iterator it = _listContainer.begin();
		 it != _listContainer.end(); ++it) {
		if (index % 2 == 1)
			std::cout << "[" << *it << "] ";
		else
			std::cout << *it << " ";
		index++;
	}
	std::cout << std::endl;
}

void PmergeMe::printListAid() {
	int index = 0;
	std::cout << "Elements in listAid:   ";
	for (std::list<int>::const_iterator it = _listAidContainer.begin();
		 it != _listAidContainer.end(); ++it) {
		if (index % 2 == 1)
			std::cout << "[" << *it << "] ";
		else
			std::cout << *it << " ";
		index++;
	}
	std::cout << std::endl;
}
// TEST FUNCTIONS
