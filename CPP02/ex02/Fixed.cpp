//Fixed.cpp
#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0) {}
Fixed::Fixed(const Fixed& other) : _raw(other._raw) {}
Fixed& Fixed::operator=(const Fixed& other) { if (this != &other) _raw = other._raw; return *this; }
Fixed::~Fixed() {}

Fixed::Fixed(int n) { _raw = n << _fracBits; }
Fixed::Fixed(float f) { _raw = static_cast<int>(std::roundf(f * static_cast<float>(1 << _fracBits))); }

int Fixed::getRawBits(void) const { return _raw; }
void Fixed::setRawBits(int const raw) { _raw = raw; }
float Fixed::toFloat(void) const { return static_cast<float>(_raw) / static_cast<float>(1 << _fracBits); }
int Fixed::toInt(void) const { return _raw >> _fracBits; }

bool Fixed::operator>(const Fixed& rhs) const { return _raw > rhs._raw; }
bool Fixed::operator<(const Fixed& rhs) const { return _raw < rhs._raw; }
bool Fixed::operator>=(const Fixed& rhs) const { return _raw >= rhs._raw; }
bool Fixed::operator<=(const Fixed& rhs) const { return _raw <= rhs._raw; }
bool Fixed::operator==(const Fixed& rhs) const { return _raw == rhs._raw; }
bool Fixed::operator!=(const Fixed& rhs) const { return _raw != rhs._raw; }

Fixed Fixed::operator+(const Fixed& rhs) const { Fixed r; r._raw = _raw + rhs._raw; return r; }
Fixed Fixed::operator-(const Fixed& rhs) const { Fixed r; r._raw = _raw - rhs._raw; return r; }
Fixed Fixed::operator*(const Fixed& rhs) const { return Fixed(this->toFloat() * rhs.toFloat()); }
Fixed Fixed::operator/(const Fixed& rhs) const { return Fixed(this->toFloat() / rhs.toFloat()); }

Fixed& Fixed::operator++() { ++_raw; return *this; }
Fixed  Fixed::operator++(int) { Fixed t(*this); ++_raw; return t; }
Fixed& Fixed::operator--() { --_raw; return *this; }
Fixed  Fixed::operator--(int) { Fixed t(*this); --_raw; return t; }

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a._raw <= b._raw) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a._raw <= b._raw) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a._raw >= b._raw) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a._raw >= b._raw) ? a : b; }

std::ostream& operator<<(std::ostream& os, const Fixed& v) { os << v.toFloat(); return os; }
