//HumanB.cpp

#include "HumanB.hpp"
#include <iostream>
HumanB::HumanB(const std::string& name): name_(name), weapon_(0) {}
void HumanB::setWeapon(Weapon& weapon) { weapon_ = &weapon; }
void HumanB::attack() const {
  if (!weapon_) return;
  std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}
