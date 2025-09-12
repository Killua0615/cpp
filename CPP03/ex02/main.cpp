//main.cpp
#include "FragTrap.hpp"

int main() {
  // Construction chaining: ClapTrap → FragTrap
  FragTrap f("Fiona");          // 先に ClapTrap ctor、続いて FragTrap ctor
  f.attack("Target1");
  f.highFivesGuys();
  f.takeDamage(42);
  f.beRepaired(10);

  // Polymorphism & virtual dtor check
  ClapTrap* p = new FragTrap("Poly");
  p->attack("Target2");         // 動的ディスパッチで FragTrap::attack
  delete p;                     // 破棄は FragTrap dtor → ClapTrap dtor の順

  // Copy semantics (rule of three)
  FragTrap cpy(f);              // copy ctor
  FragTrap g("Gina");
  g = f;                        // copy assignment
  cpy.attack("CopyAttack");
  g.attack("AssignedAttack");

  return 0;                     // 自動変数は逆順で dtor（Frag→Clap の連鎖）
}
