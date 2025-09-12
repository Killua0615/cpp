//ScavTrap.cpp
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  _hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
  std::cout << "ScavTrap default constructor\n";
}
//duo to (: ClapTrap(name)) "desplay ClapTrap Serena ctor" in outputs first
//after The ScavTrap constructor body executes, overwriting the ability values
//Outputs "ScavTrap Serena ctor"
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = 100; _energyPoints = 50; _attackDamage = 20;
  std::cout << "ScavTrap " << _name << " constructor\n";
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  std::cout << "ScavTrap copy constructor\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << "ScavTrap copy assign\n";
  if (this != &other) ClapTrap::operator=(other);
  return *this;
}
ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor\n";
}

void ScavTrap::attack(const std::string& target) {
  if (_hitPoints <= 0 || _energyPoints <= 0) {
    std::cout << "ScavTrap " << _name << " cannot attack\n";
    return;
  }
  --_energyPoints;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
