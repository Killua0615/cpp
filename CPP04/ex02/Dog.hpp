//Dog.hpp
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
  Brain* brain; //A pointer for owning one's own dedicated 'brain' object
public:
  Dog();
  Dog(const Dog& o);
  Dog& operator=(const Dog& o);
  virtual ~Dog();

  virtual void makeSound() const;
  Brain* getBrain() const;
};
#endif
