//AMateria.hpp
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;
class AMateria {
protected:
  std::string _type;
public:
  AMateria(std::string const& type);
  AMateria(AMateria const& o);
  AMateria& operator=(AMateria const& o);
  virtual ~AMateria();
  std::string const& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};
#endif
