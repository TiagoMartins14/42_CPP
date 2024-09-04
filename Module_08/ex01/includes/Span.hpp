#pragma once
#include <vector>

class Span {
   private:
	unsigned int _maxSize;
	std::vector<int> _intContainer;

   public:
	Span(unsigned int N);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
};
