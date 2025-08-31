//HumanA.hpp
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
  std::string name_;
  Weapon& weapon_;
public:
  HumanA(const std::string& name, Weapon& weapon);
  void attack() const;
};

#endif
