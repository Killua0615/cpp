//Animal.cpp
#include "Animal.hpp"

Animal::Animal() : type("") { std::cout << "Animal ctor\n"; }
Animal::Animal(const Animal& o) : type(o.type) { std::cout << "Animal copy ctor\n"; }
Animal& Animal::operator=(const Animal& o){ std::cout << "Animal copy assign\n"; if(this!=&o) type=o.type; return *this; }
Animal::~Animal(){ std::cout << "Animal dtor\n"; }

std::string Animal::getType() const { return type; }
