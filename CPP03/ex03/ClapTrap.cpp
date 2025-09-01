//ClapTrap.cpp
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default ctor\n";
}
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << _name << " ctor\n";
}
ClapTrap::ClapTrap(const ClapTrap& other)
: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
  std::cout << "ClapTrap copy ctor\n";
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << "ClapTrap copy assign\n";
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  return *this;
}
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap dtor\n";
}
void ClapTrap::attack(const std::string& target) {
  if (_hitPoints <= 0 || _energyPoints <= 0) { std::cout << "ClapTrap " << _name << " cannot attack\n"; return; }
  --_energyPoints;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints <= 0) { std::cout << "ClapTrap " << _name << " is already out\n"; return; }
  int d = static_cast<int>(amount);
  _hitPoints -= d;
  if (_hitPoints < 0) _hitPoints = 0;
  std::cout << "ClapTrap " << _name << " takes " << d << " damage\n";
}
void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints <= 0 || _energyPoints <= 0) { std::cout << "ClapTrap " << _name << " cannot repair\n"; return; }
  --_energyPoints;
  int h = static_cast<int>(amount);
  _hitPoints += h;
  std::cout << "ClapTrap " << _name << " is repaired by " << h << "\n";
}
