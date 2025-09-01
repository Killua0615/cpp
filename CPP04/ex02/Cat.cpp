//Cat.cpp
#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) { type="Cat"; std::cout << "Cat ctor\n"; }
Cat::Cat(const Cat& o) : Animal(o), brain(new Brain(*o.brain)) { std::cout << "Cat copy ctor\n"; }
Cat& Cat::operator=(const Cat& o){
  std::cout << "Cat copy assign\n";
  if(this!=&o){ Animal::operator=(o); delete brain; brain=new Brain(*o.brain); }
  return *this;
}
Cat::~Cat(){ delete brain; std::cout << "Cat dtor\n"; }
void Cat::makeSound() const { std::cout << "Meow!\n"; }
Brain* Cat::getBrain() const { return brain; }
