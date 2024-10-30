#include "Span.hpp"
#include <iostream>

#define MIN 1
#define MAX 10000

int main() {

  Span sp = Span(5);

  sp.fillSpan(MIN, MAX);

  // Trying to add MAX + 1 element
  try {
    sp.addNumber(0);
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }

  try {
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (const std::logic_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }

  return 0;
}
