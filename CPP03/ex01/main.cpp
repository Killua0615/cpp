//main.cpp
#include "ScavTrap.hpp"

int main() {
  //Basic ScavTrap behavior
  ScavTrap s("Serena");
  s.attack("Target");   // Uses ScavTrap::attack (EP -1; prints damage number only, no HP applied)
  s.guardGate();        // ScavTrap-specific action (prints a message only)
  s.takeDamage(30);     // Reuses ClapTrap logic: HP -= 30, clamped at 0
  s.beRepaired(10);     // Reuses ClapTrap logic: EP -1, HP += 10
  std::cout << "\n";

  //Polymorphism check: dispatch ScavTrap::attack bc 'virtual'
  ClapTrap& br = s;
  // Dynamic dispatch → ScavTrap::attack
  // Becoude Overriding and being virtual
  br.attack("PolyRef"); 
  ClapTrap* bp = new ScavTrap("Sera");
  bp->attack("PolyPtr"); // Dynamic dispatch → ScavTrap::attack
  delete bp;             // Virtual destructor: ScavTrap dtor then ClapTrap dtor
  std::cout << "\n";

  //Derived copy semantics (copy ctor / copy assignment)
  ScavTrap a("A");
  ScavTrap copy(a);      // Copy constructor
  ScavTrap b("B");
  b = a;                 // Copy assignment (no self-assignment)
  copy.attack("FromCopy");
  b.attack("FromAssigned");
  std::cout << "\n";

  return 0;
}

//5times call the destructor
//1.ScavTrap s("Serena");
//2.ClapTrap* bp = new ScavTrap("Sera");
//3.ScavTrap a("A");
//4.ScavTrap copy(a);
//5.ScavTrap b("B");
