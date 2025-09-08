//Fixed.hpp
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
  private:
    int                 _raw;
    static const int    _fracBits; //Meaning the fractional part is 8 bits

  public:
    Fixed();                       //Default constructor: Initialise _raw to 0
    Fixed(const Fixed& other);     //Copy constructor: Copies the _raw of another instance
    Fixed& operator=(const Fixed& other);//Assignment operator: Copy _raw after self-check
    ~Fixed();                      //Destructor
    int  getRawBits(void) const;   //Return the current raw
    void setRawBits(int const raw);//Rewrite the raw file
};

#endif
