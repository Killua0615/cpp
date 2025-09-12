//main.cpp
#include "ClapTrap.hpp"

int main() {
  ClapTrap a("Alpha");//Create ClapTrap object named "Alpha", a(variable name)
  ClapTrap b("Beta"); //Create ClapTrap object named "Beta", b(variable name)
  a.attack("Beta");   //a's HP > 0 and EP > 0 → OK
  b.takeDamage(3);    //HP b: 10 → 7
  b.beRepaired(2);    //b's EP changes from 10 to 9, HP changes from 7 to 9.
  return 0;
}
