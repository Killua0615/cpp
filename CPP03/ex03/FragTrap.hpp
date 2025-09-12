//FragTrap.hpp
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

// change to virtual public
class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& other);
  virtual ~FragTrap();

  virtual void attack(const std::string& target);
  void highFivesGuys(void);
};
#endif
