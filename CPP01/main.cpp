//main.c
#include "Zombie.hpp"

int main() {
  Zombie s("stack");
  s.announce();

  Zombie* h = newZombie("heap");
  h->announce();
  delete h;

  randomChump("stack(auto)");
  return 0;
}