#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) {
	if (this != &other) *this = other;
}
