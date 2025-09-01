//WrongCat.hpp
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat& o);
  WrongCat& operator=(const WrongCat& o);
  ~WrongCat();
  void makeSound() const;
};
#endif
