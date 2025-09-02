//Cure.cpp
#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>
Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const& o) : AMateria(o) {}
Cure& Cure::operator=(Cure const& o){ AMateria::operator=(o); return *this; }
Cure::~Cure() {}
AMateria* Cure::clone() const { return new Cure(*this); }
void Cure::use(ICharacter& target){
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
