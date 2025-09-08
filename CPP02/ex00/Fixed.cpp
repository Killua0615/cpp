//Fixed.cpp
#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0) { //Initialise to zero
  std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) : _raw(other._raw) {//copy constructor
  std::cout << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& other) { //Copy assignment operator
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) _raw = other._raw; //If it is a different object, perform the assignment
  return *this;            //Returns a reference to the left-hand side object itself.
}
Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _raw;
}
void Fixed::setRawBits(int const raw) {
  _raw = raw;
}
