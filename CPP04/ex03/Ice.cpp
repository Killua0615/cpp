//Ice.cpp
#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>
Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const& o) : AMateria(o) {}
Ice& Ice::operator=(Ice const& o){ AMateria::operator=(o); return *this; }
Ice::~Ice() {}
AMateria* Ice::clone() const { return new Ice(*this); }
void Ice::use(ICharacter& target){
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
