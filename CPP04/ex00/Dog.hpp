#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog& o);
  Dog& operator=(const Dog& o);
  virtual ~Dog();
  virtual void makeSound() const;
};
#endif
