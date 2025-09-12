//ClapTrap.cpp
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) { 
  std::cout << "ClapTrap default ctor\n";         //Default constructor without name
}
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << _name << " ctor\n"; //Default constructor with name
}
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
  std::cout << "ClapTrap copy ctor\n";            //When creating a "new" object using an existing object, determine how to duplicate it.
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << "ClapTrap copy assign\n";          //Copy assignment operator
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor\n";
}
void ClapTrap::attack(const std::string& target) {
  if (_hitPoints <= 0 || _energyPoints <= 0) {
    std::cout << "ClapTrap " << _name << " cannot attack\n";
    return;
  }
  --_energyPoints; //1 point reduce
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _name << " is already out\n";
    return;
  }
  int dmg = static_cast<int>(amount); //Since amount(unsigned int), changed it to int, put it in the dmg, and calculated it using the same int _hitPoints.
  _hitPoints -= dmg;                  //Same _hitPoints = _hitPoints - dmg
  if (_hitPoints < 0) _hitPoints = 0;
  std::cout << "ClapTrap " << _name << " takes " << dmg << " damage\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints <= 0 || _energyPoints <= 0) {
    std::cout << "ClapTrap " << _name << " cannot repair\n";
    return;
  }
  --_energyPoints; //1 point reduce
  int heal = static_cast<int>(amount); ////Since amount(unsigned int), changed it to int, put it in the heal, and calculated it using the same int _hitPoints.
  _hitPoints += heal;
  std::cout << "ClapTrap " << _name << " is repaired by " << heal << "\n";
}
