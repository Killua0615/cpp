//Character.hpp
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character : public ICharacter {
private:
  std::string _name;
  AMateria* _inv[4];
  AMateria* _floor[128];
  int _floorCount;
  void clearInv();
  void cloneFrom(Character const& o);
public:
  Character(std::string const& name);
  Character(Character const& o);
  Character& operator=(Character const& o);
  virtual ~Character();
  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};
#endif
