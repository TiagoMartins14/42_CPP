#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
   private:
	unsigned int _maxSize;
	std::vector<int> _intContainer;
	int *_sequence;
	size_t _sequenceSize;

   public:
	Span(unsigned int N);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span();

	void setSequence(int sequence[], size_t size);

	void addNumber(int num);
	void fillSpan();
	int shortestSpan();
	int longestSpan();
};
