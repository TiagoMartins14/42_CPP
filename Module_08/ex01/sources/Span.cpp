#include "Span.hpp"

#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : _maxSize(N) { _intContainer.reserve(_maxSize); }

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_intContainer = other._intContainer;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_intContainer.size() >= _maxSize)
		throw std::overflow_error("Span is full.");
	_intContainer.push_back(num);
}

int Span::shortestSpan() {
	if (_intContainer.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sortedContainer = _intContainer;
	std::sort(sortedContainer.begin(), sortedContainer.end());

	int shortestSpan = sortedContainer[1] - sortedContainer[0];
	int span;
	for (size_t i = 1; i < sortedContainer.size() - 1; i++) {
		span = sortedContainer[i + 1] - sortedContainer[i];
		if (span < shortestSpan) shortestSpan = span;
	}
	return shortestSpan;
}

int Span::longestSpan() {
	if (_intContainer.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sortedContainer = _intContainer;
	std::sort(sortedContainer.begin(), sortedContainer.end());

	int longestSpan = sortedContainer[1] - sortedContainer[0];
	int span;
	for (size_t i = 1; i < sortedContainer.size() - 1; i++) {
		span = sortedContainer[i + 1] - sortedContainer[i];
		if (span < longestSpan) longestSpan = span;
	}
	return longestSpan;
}
