#ifndef ARRAY_TPP
#define ARRAY_TPP

//default constructor
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

//constructor with a size parameter
template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (_size == 0)
		return;
	_data = new T[_size]();
}

//copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(other._size)
{
	if (_size == 0)
		return;
	_data = new T[_size]();
	std::size_t i = 0;
	while (i < _size)
	{
		_data[i] = other._data[i];
		i++;
	}
}

//distractor
template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

//copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;

	delete[] _data;
	_data = NULL;
	_size = other._size;

	if (_size == 0)
		return *this;

	_data = new T[_size]();
	std::size_t i = 0;
	while (i < _size)
	{
		_data[i] = other._data[i];
		i++;
	}
	return *this;
}

//operator not const
template <typename T>
T& Array<T>::operator[](std::size_t index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

//const operator
template <typename T>
const T& Array<T>::operator[](std::size_t index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

//return size()
template <typename T>
std::size_t Array<T>::size() const
{
	return _size;
}

#endif
