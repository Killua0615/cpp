//Zombie.cpp
#include "Zombie.hpp"

Zombie::Zombie() : _name("") {}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie() {}
void Zombie::setName(const std::string& name){ _name = name; }
void Zombie::announce(){ std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
