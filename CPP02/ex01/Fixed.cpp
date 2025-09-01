//Fixed.cpp
#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) : _raw(other._raw) {
  std::cout << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) _raw = other._raw;
  return *this;
}
Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int n) {
  std::cout << "Int constructor called" << std::endl;
  _raw = n << _fracBits;
}
Fixed::Fixed(float f) {
  std::cout << "Float constructor called" << std::endl;
  _raw = static_cast<int>(std::roundf(f * (1 << _fracBits)));
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _raw;
}
void Fixed::setRawBits(int const raw) {
  _raw = raw;
}
float Fixed::toFloat(void) const {
  return static_cast<float>(_raw) / static_cast<float>(1 << _fracBits);
}
int Fixed::toInt(void) const {
  return _raw >> _fracBits;
}

#include <ostream>
std::ostream& operator<<(std::ostream& os, const Fixed& v) {
  os << v.toFloat();
  return os;
}
