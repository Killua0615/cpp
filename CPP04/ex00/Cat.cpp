//Cat.cpp
#include "Cat.hpp"

Cat::Cat(){ type="Cat"; std::cout << "Cat ctor\n"; }
Cat::Cat(const Cat& o) : Animal(o){ std::cout << "Cat copy ctor\n"; }
Cat& Cat::operator=(const Cat& o){ std::cout << "Cat copy assign\n"; if(this!=&o) Animal::operator=(o); return *this; }
Cat::~Cat(){ std::cout << "Cat dtor\n"; }
void Cat::makeSound() const { std::cout << "Meow!\n"; }
