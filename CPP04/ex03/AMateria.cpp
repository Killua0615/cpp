//AMateria.cpp
#include "AMateria.hpp"
#include "ICharacter.hpp"
AMateria::AMateria(std::string const& type) : _type(type) {}
AMateria::AMateria(AMateria const& o) : _type(o._type) {}
AMateria& AMateria::operator=(AMateria const& o){ if(this!=&o){ _type=o._type; } return *this; }
AMateria::~AMateria() {}
std::string const& AMateria::getType() const { return _type; }
void AMateria::use(ICharacter&){ (void)0; }
