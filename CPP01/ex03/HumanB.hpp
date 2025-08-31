//HumanB.hpp
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
  std::string name_;
  Weapon* weapon_;
public:
  HumanB(const std::string& name);
  void setWeapon(Weapon& weapon);
  void attack() const;
};

#endif
