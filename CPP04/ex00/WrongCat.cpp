//WrongCat.cpp
#include "WrongCat.hpp"

WrongCat::WrongCat(){ type="WrongCat"; std::cout << "WrongCat ctor\n"; }
WrongCat::WrongCat(const WrongCat& o) : WrongAnimal(o){ std::cout << "WrongCat copy ctor\n"; }
WrongCat& WrongCat::operator=(const WrongCat& o){ std::cout << "WrongCat copy assign\n"; if(this!=&o) WrongAnimal::operator=(o); return *this; }
WrongCat::~WrongCat(){ std::cout << "WrongCat dtor\n"; }
void WrongCat::makeSound() const { std::cout << "Meow?\n"; }
