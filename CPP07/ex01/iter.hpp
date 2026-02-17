#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, const std::size_t length, void (*f)(T &))
{
	std::size_t i = 0;
	if (!array || !f)
		return ;
	while (i < length)
	{
		f(array[i]);
		i++;
	}
}

template <typename T>
void iter(const T *array, const std::size_t length, void (*f)(const T &))
{
	std::size_t i = 0;
	if (!array || !f)
		return ;
	while (i < length)
	{
		f(array[i]);
		i++;
	}
}

#endif
