//main.cpp
#include "ScavTrap.hpp"

int main() {
  ScavTrap s("Serena");
  s.attack("Target");
  s.guardGate();
  s.takeDamage(30);
  s.beRepaired(10);
  return 0;
}
