#include "Span.hpp"
#include <iostream>

int main()
{

    Span sp = Span(5);

    /* int spanArray[] = {2, 7, 14, 20, 40};

    sp.setSequence(spanArray, sizeof(spanArray) / sizeof(int));
    sp.fillSpan(); */

    // Adding 5 elements
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch (const std::overflow_error &e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }

    // Trying to add a sixth element
    try {
        sp.addNumber(20);
    }
     catch (const std::overflow_error &e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }

    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::logic_error &e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }

    return 0;
}
