//DiamondTrap.cpp
#include "DiamondTrap.hpp"

// The most-derived class (DiamondTrap) initializes the virtual base ClapTrap.
DiamondTrap::DiamondTrap()
: ClapTrap("_clap_name"), FragTrap(), ScavTrap(), _name("") {
  // Attribute policy: HP/ATK from FragTrap, EP from ScavTrap
  _hitPoints    = 100; // FragTrap
  _energyPoints = 50;  // ScavTrap
  _attackDamage = 30;  // FragTrap
  std::cout << "DiamondTrap default ctor\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
  // Attribute policy: HP/ATK from FragTrap, EP from ScavTrap
  _hitPoints    = 100; // FragTrap
  _energyPoints = 50;  // ScavTrap
  _attackDamage = 30;  // FragTrap
  std::cout << "DiamondTrap " << _name << " ctor\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
  std::cout << "DiamondTrap copy ctor\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  std::cout << "DiamondTrap copy assign\n";
  if (this != &other) {
    // Copy the shared ClapTrap state once (virtual base)
    ClapTrap::operator=(other);
    _name = other._name;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap dtor\n";
}

// Use ScavTrap-style attack (explicitly call to avoid ambiguity)
void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  // Print both: own name and the underlying ClapTrap name
  std::cout << "DiamondTrap name: " << _name << " | ClapTrap name: " << ClapTrap::_name << "\n";
}
