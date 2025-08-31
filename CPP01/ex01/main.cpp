//main.cpp
#include "Zombie.hpp"

int main(){
  int n = 3;
  Zombie* h = zombieHorde(n, "horde");
  if (!h) return 0;
  int i = 0;
  while (i < n) {
      h[i].announce();
      i++;
  }
  delete[] h;
  return 0;
}
