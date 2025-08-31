//Zombie.hpp
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
  std::string _name;

public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void setName(const std::string& name);
  void announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif
