//main.cpp
#include "Fixed.hpp"

//Code implementing an 8-bit fixed-point decimal class
//testing generation from int/float
//conversion to float/int, and stream output (<<).
int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);

  a = Fixed(1234.4321f);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;
  return 0;
}

//Fixed a; initialisation
//b(10): Constructed from int. b._raw = 10 << 8 = 2560 (toFloat() returns 10.0, toInt() returns 10)
//c(42.42f): Constructed from float. c._raw = roundf(42.42 * 256) = 10860 toFloat() yields 10860/256 = 42.421875, toInt() yields 42
//d(b): Copy construction. d._raw = 2560
//(1234.4321f); Create a temporary object from a float and assign it._raw = roundf(1234.4321*256) = 316015, toFloat() 316015/256 = 1234.43359375