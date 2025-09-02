//Ice.hpp
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(Ice const& o);
  Ice& operator=(Ice const& o);
  virtual ~Ice();
  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};
#endif
