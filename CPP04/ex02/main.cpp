//main.cpp
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(){
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << "\n";

  std::cout << j->getType() << std::endl;
  std::cout << i->getType() << std::endl;
  std::cout << "\n";

  j->makeSound();
  i->makeSound();
  std::cout << "\n";

  delete j;
  delete i;
  return 0;
}
