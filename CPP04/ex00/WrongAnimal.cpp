//WrongAnimal.cpp
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type(""){ std::cout << "WrongAnimal ctor\n"; }
WrongAnimal::WrongAnimal(const WrongAnimal& o) : type(o.type){ std::cout << "WrongAnimal copy ctor\n"; }
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& o){ std::cout << "WrongAnimal copy assign\n"; if(this!=&o) type=o.type; return *this; }
WrongAnimal::~WrongAnimal(){ std::cout << "WrongAnimal dtor\n"; }
std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const { std::cout << "(wrong animal sound)\n"; }
