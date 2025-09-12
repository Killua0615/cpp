//ClapTrap.hpp
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
  protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

  public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    virtual ~ClapTrap();

    //If a base class declares a virtual member, and it with the same signature
    //the derived implementation overrides it.
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif

//Override: Rewrites a base class's virtual function with the same signature (dynamic dispatch).
//Overload: Adds functions with the same name but different arguments within the same class (static dispatch).

