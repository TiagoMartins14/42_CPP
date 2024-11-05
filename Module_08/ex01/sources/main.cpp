#include "Span.hpp"
#include <iostream>

#define MIN 1
#define MAX 10000

int main() {

  // sp1 will use addNumber()
  Span sp1 = Span(5);
  std::cout << " ----- Span(5) ----- " << std::endl << std::endl;

  std::cout << "Using addNumber..." << std::endl;
  try {
    sp1.addNumber(1);
    std::cout << "SUCCESS!" << std::endl;
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }
  try {
    sp1.addNumber(2);
    std::cout << "SUCCESS!" << std::endl;
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }
  try {
    sp1.addNumber(3);
    std::cout << "SUCCESS!" << std::endl;
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }
  try {
    sp1.addNumber(4);
    std::cout << "SUCCESS!" << std::endl;
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }
  try {
    sp1.addNumber(5);
    std::cout << "SUCCESS!" << std::endl;
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }

  // Trying to add sp.size() + 1 element
  std::cout << "Trying to add sp.size() + 1 element... " << std::endl;

  try {
    sp1.addNumber(0);
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }

  try {
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
  } catch (const std::logic_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }

  std::cout << std::endl << " ----- Span(MAX) ----- " << std::endl << std::endl;

  // sp2 will use fillSpan()
  Span sp2 = Span(MAX);

  std::cout << "Using fillSpan()..." << std::endl;
  try {
    sp2.fillSpan(MIN, MAX);
    std::cout << "SUCCESS!" << std::endl;
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }

  std::cout << "Trying to add sp.size() + 1 element... " << std::endl;
  try {
    sp1.addNumber(MAX + 1);
  } catch (const std::overflow_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }

  try {
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
  } catch (const std::logic_error &e) {
    std::cerr << "Logic error: " << e.what() << std::endl;
  }

  return 0;
}
