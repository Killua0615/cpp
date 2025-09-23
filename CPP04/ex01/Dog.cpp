//Dog.cpp
#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) { type="Dog"; std::cout << "Dog ctor\n"; }
Dog::Dog(const Dog& o) : Animal(o), brain(new Brain(*o.brain)) { std::cout << "Dog copy ctor\n"; }
Dog& Dog::operator=(const Dog& o){
  std::cout << "Dog copy assign\n";
  if(this!=&o){ Animal::operator=(o); delete brain; brain=new Brain(*o.brain); }
  return *this;
}
Dog::~Dog(){ delete brain; std::cout << "Dog dtor\n"; }

void Dog::makeSound() const { std::cout << "Woof!\n"; }
Brain* Dog::getBrain() const { return brain; }
