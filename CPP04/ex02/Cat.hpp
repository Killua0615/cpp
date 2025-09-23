//Cat.hpp
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
  Brain* brain;
public:
  Cat();
  Cat(const Cat& o);
  Cat& operator=(const Cat& o);
  virtual ~Cat();

  virtual void makeSound() const;
  Brain* getBrain() const;
};
#endif
