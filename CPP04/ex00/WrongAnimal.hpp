//WrongAnimal.hpp
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
  std::string type;
public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& o);
  WrongAnimal& operator=(const WrongAnimal& o);
  ~WrongAnimal();
  std::string getType() const;
  void makeSound() const;
};
#endif
