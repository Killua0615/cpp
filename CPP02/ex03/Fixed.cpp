//Fixed.cpp
#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0) {}
Fixed::Fixed(const Fixed& other) : _raw(other._raw) {}
Fixed& Fixed::operator=(const Fixed& other){ if(this!=&other) _raw=other._raw; return *this; }
Fixed::~Fixed() {}

Fixed::Fixed(int n){ _raw = n << _fracBits; }
Fixed::Fixed(float f){ _raw = static_cast<int>(std::roundf(f * static_cast<float>(1 << _fracBits))); }

int   Fixed::getRawBits(void) const { return _raw; }
void  Fixed::setRawBits(int const raw){ _raw = raw; }
float Fixed::toFloat(void) const { return static_cast<float>(_raw) / static_cast<float>(1 << _fracBits); }
int   Fixed::toInt(void) const { return _raw >> _fracBits; }
