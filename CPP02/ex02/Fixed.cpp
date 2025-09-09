/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:27:18 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/09 21:54:53 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0) {} //Default constructor
Fixed::Fixed(const Fixed& other) : _raw(other._raw) {} //Copy constructor 
Fixed& Fixed::operator=(const Fixed& other) { if (this != &other) _raw = other._raw; return *this; } //Copy assignment operator 
Fixed::~Fixed() {} //Destructor

//Floating-point ⇔ Fixed-point
//Integer → Fixed-point
Fixed::Fixed(int n) { _raw = n << _fracBits; } //_raw = n << 8（= n * 256）
//Real number → Fixed-point
Fixed::Fixed(float f) {
    float scaled = f * static_cast<float>(1 << _fracBits);
    if (scaled >= 0)
        _raw = static_cast<int>(scaled + 0.5f);
    else
        _raw = static_cast<int>(scaled - 0.5f);
}

int Fixed::getRawBits(void) const { return _raw; }
void Fixed::setRawBits(int const raw) { _raw = raw; }
//For human-readable decimal format, enabling integration with external APIs and standard libraries.
//Convert back to a normal real number(For display and calculation purposes)
float Fixed::toFloat(void) const { return static_cast<float>(_raw) / static_cast<float>(1 << _fracBits); }
//Extract the integer part
int Fixed::toInt(void) const { return _raw >> _fracBits; }

//Defining the "behaviour" of operators such as <, >=, <=, ==, and != yourself
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

//++a, --a
Fixed& Fixed::operator++() { ++_raw; return *this; }
Fixed  Fixed::operator++(int) { Fixed t(*this); ++_raw; return t; }
//a++, a--
Fixed& Fixed::operator--() { --_raw; return *this; }
Fixed  Fixed::operator--(int) { Fixed t(*this); --_raw; return t; }

//Return the smaller (or larger) one by reference.
//Since <= and >= are used, it returns the first argument when values are equal.
//Non-const version and const version
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a._raw <= b._raw) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a._raw <= b._raw) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a._raw >= b._raw) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a._raw >= b._raw) ? a : b; }

//Overload (for output)
std::ostream& operator<<(std::ostream& os, const Fixed& v) { os << v.toFloat(); return os; }
