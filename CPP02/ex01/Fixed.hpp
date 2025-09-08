//Fixed.hpp
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iosfwd>
#include <iostream>
#include <cmath>
#include <ostream>

class Fixed {
private:
  int              _raw;      //Store the integer rounded to the nearest integer of a real number × 2⁸ (=256) in _raw (fixed-point)
  static const int _fracBits; //Fractional part bit count: _fracBits = 8

public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  Fixed(int n);
  Fixed(float f);

  int   getRawBits(void) const;
  void  setRawBits(int const raw);
  float toFloat(void) const; //toFloat() restores the stored integer to its original floating-point value (toFloat() = _raw / 256.0f → 2560 / 256 = 10.0)
  int   toInt(void) const;   //toInt() discards the fractional part.
};

std::ostream& operator<<(std::ostream& os, const Fixed& v);

#endif
