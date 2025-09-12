//FragTrap.cpp
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  _hitPoints    = 100; _energyPoints = 100; _attackDamage = 30;
  std::cout << "FragTrap default constructor\n";
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints    = 100; _energyPoints = 100; _attackDamage = 30;
  std::cout << "FragTrap " << _name << " constructor\n";
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap copy constructor\n";
}
FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << "FragTrap copy assign\n";
  if (this != &other) {
    ClapTrap::operator=(other); // 基底部分を安全にコピー
  }
  return *this;
}
FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor\n";
}

void FragTrap::attack(const std::string& target) {
  if (_hitPoints <= 0 || _energyPoints <= 0) {
    std::cout << "FragTrap " << _name << " cannot attack\n";
    return;
  }
  --_energyPoints;
  std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << _name << " requests a positive high five!\n";
}
