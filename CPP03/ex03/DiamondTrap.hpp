//DiamondTrap.hpp
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

// DiamondTrap is half FragTrap, half ScavTrap.
// With virtual inheritance above, there will be a single ClapTrap subobject.
class DiamondTrap : public FragTrap, public ScavTrap {
private:
  // Must have the exact same variable name as in ClapTrap (here: _name)
  std::string _name;

public:
  DiamondTrap();
  explicit DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& other);
  DiamondTrap& operator=(const DiamondTrap& other);
  virtual ~DiamondTrap();

  // attack() must follow ScavTrap behavior
  virtual void attack(const std::string& target);

  // Print both DiamondTrap's own name and the ClapTrap name
  void whoAmI();
};

#endif
