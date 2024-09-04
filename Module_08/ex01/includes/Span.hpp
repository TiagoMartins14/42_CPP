#pragma once

class Span {
   private:
	unsigned int _N;

   public:
	Span(unsigned int N);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
};
