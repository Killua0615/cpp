//ClapTrap.hpp
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
  private:
    std::string _name; //Character name
    int _hitPoints;    //(HP): When it (0) cannot act.
    int _energyPoints; //(EP): Consumes 1 point per attack or self-healing. Cannot act (0)
    int _attackDamage; //(AP): Attack power

  public:
    ClapTrap();                                //Default constructor
    ClapTrap(const std::string& name);         //Named constructor
    ClapTrap(const ClapTrap& other);           //Copy constructor
    ClapTrap& operator=(const ClapTrap& other);//Copy assignment operator
    ~ClapTrap();

    void attack(const std::string& target); //If HP>0 and EP>0, Consumes 1(EP) and displays target attacked.
    void takeDamage(unsigned int amount);   //Reduce HP. Do not reduce below (0)
    void beRepaired(unsigned int amount);   //If If HP>0 and EP>0, Repaired HP.
};

#endif
