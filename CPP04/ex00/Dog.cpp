//Dog.cpp
#include "Dog.hpp"

Dog::Dog(){ type="Dog"; std::cout << "Dog ctor\n"; }
Dog::Dog(const Dog& o) : Animal(o){ std::cout << "Dog copy ctor\n"; }
Dog& Dog::operator=(const Dog& o){ std::cout << "Dog copy assign\n"; if(this!=&o) Animal::operator=(o); return *this; }
Dog::~Dog(){ std::cout << "Dog dtor\n"; }
void Dog::makeSound() const { std::cout << "Woof!\n"; }
