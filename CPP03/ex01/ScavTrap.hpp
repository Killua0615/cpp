//ScavTrap.hpp
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap { //(:public ClapTrap) inherits from public interface of ClapTrap
  public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    virtual ~ScavTrap();

    virtual void attack(const std::string& target);
    void guardGate();            //Just Display of plain text
};

#endif
