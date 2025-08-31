//zombieHorde.cpp
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
  if (N <= 0) return NULL;
  Zombie* h = new Zombie[N];
  int i = 0;
  while (i < N) {
    h[i].setName(name);
    i++;
  }
  return h;
}
