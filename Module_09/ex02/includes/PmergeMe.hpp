#pragma once
#include <cstdlib>
#include <iostream>
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
  void createContainers(char **argv);

public:
  PmergeMe(char **argv);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  // Vector functions
  void vectorOrderPairs();
  void vectorPutPairsInAscendingOrder();
  void listPutPairsInAscendingOrder();
  // List functions
  void listOrderPairs();

  // TEST FUNCTIONS
  void printVector();

  void printList();
};
