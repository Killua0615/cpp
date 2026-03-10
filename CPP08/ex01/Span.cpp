#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &src) : _n(src._n), _v(src._v) {}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_v.size() >= _n)
		throw std::overflow_error("Span is full");
	_v.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_v.size() <= 1)
		throw std::logic_error("Not enough elements to find a span");
	std::vector<int> sorted(_v);
	std::sort(sorted.begin(), sorted.end());
	unsigned int min = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 2; i < sorted.size(); i++)
	{
		unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (diff < min)
			min = diff;
	}
	return min;
}

unsigned int Span::longestSpan() const
{
	if (_v.size() <= 1)
		throw std::logic_error("Not enough elements to find a span");
	int minVal = *std::min_element(_v.begin(), _v.end());
	int maxVal = *std::max_element(_v.begin(), _v.end());
	return static_cast<unsigned int>(maxVal - minVal);
}
