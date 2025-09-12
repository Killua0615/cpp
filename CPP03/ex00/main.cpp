//main.cpp
#include "ClapTrap.hpp"

int main() {
  // Base (happy path)
  ClapTrap a("Alpha"); // HP=10, EP=10, ATK=0
  ClapTrap b("Beta");  // HP=10, EP=10, ATK=0
  a.attack("Beta");    // EP: 10->9
  b.takeDamage(3);     // HP: 10->7
  b.beRepaired(2);     // EP: 10->9, HP: 7->9

  // EP = 0 blocks actions
  for (int i = 0; i < 9; ++i) a.attack("Dummy"); // drain EP to 0
  a.attack("Dummy");   // should fail (EP==0)
  a.beRepaired(1);     // should fail (EP==0)

  // HP = 0 blocks actions
  b.takeDamage(1000);  // overkill -> HP=0
  b.attack("Anyone");  // should fail (HP==0)
  b.beRepaired(1);     // should fail (HP==0)

  // Overkill clamps to 0 and stays 0
  ClapTrap d("Delta");
  d.takeDamage(15);    // HP: 10->0
  d.takeDamage(1);     // still 0 (already out)
  return 0;
}
