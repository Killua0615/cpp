#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
private:
	unsigned int	_n;
	std::vector<int>	_v;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	Span &operator=(const Span &rhs);
	~Span();

	void	addNumber(int number);

	template <typename Iterator>
	void	addRange(Iterator begin, Iterator end)
	{
		unsigned int dist = std::distance(begin, end);
		if (_v.size() + dist > _n)
			throw std::overflow_error("Not enough space to add range");
		_v.insert(_v.end(), begin, end);
	}

	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;
};

#endif
