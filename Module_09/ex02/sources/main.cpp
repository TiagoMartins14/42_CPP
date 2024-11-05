#include "PmergeMe.hpp"

int main(int argc, char **argv) {

  if (argc >= 2) {
    PmergeMe algorithm(argv);

    algorithm.printVector();
    algorithm.printList();

    algorithm.vectorOrderPairs();
    algorithm.listOrderPairs();

    algorithm.printVector();
    algorithm.printList();
  }
}
