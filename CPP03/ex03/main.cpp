//main.cpp
#include "DiamondTrap.hpp"

int main() {
  // Construction chaining: ClapTrap (virtual base) is built once, then parents, then DiamondTrap
  DiamondTrap d("Dia");
  d.whoAmI();          // Shows "Dia" and "Dia_clap_name"
  std::cout << "\n";

  // attack must use ScavTrap behavior
  d.attack("Target");  // Consumes EP, ScavTrap-style message
  std::cout << "\n";

  // Both parent abilities are available
  d.highFivesGuys();   // FragTrap special (display only)
  d.guardGate();       // ScavTrap special (display only)
  std::cout << "\n";

  // Common ClapTrap behaviors
  d.takeDamage(42);
  d.beRepaired(10);
  std::cout << "\n";

  // Polymorphism & virtual dtor via base pointer
  ClapTrap* p = new DiamondTrap("PolyDia");
  p->attack("PolyTarget");   // Dynamic dispatch to DiamondTrap::attack → ScavTrap::attack
  delete p;                  // DiamondTrap dtor → ClapTrap dtor (safe due to virtual dtor)
  std::cout << "\n";

  // Copy semantics
  DiamondTrap cpy(d);        // copy ctor
  DiamondTrap g("Ghost");
  g = d;                     // copy assignment
  cpy.whoAmI();
  g.whoAmI();
  std::cout << "\n";

  return 0;
}
