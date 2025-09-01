//Cat.hpp
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat& o);
  Cat& operator=(const Cat& o);
  virtual ~Cat();
  virtual void makeSound() const;
};
#endif
