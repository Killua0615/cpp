//FragTrap.hpp
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap();
  explicit FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& other);
  virtual ~FragTrap();

  // override
  virtual void attack(const std::string& target);

  // special ability
  void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP
