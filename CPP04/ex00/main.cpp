//main.cpp
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
  const Animal* meta = new Animal();
  std::cout << "\n";

  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << std::endl; //display Dog
  std::cout << i->getType() << std::endl; //display Cat
  std::cout << "\n";

  //As `i` is `new Cat()`, the "virtual makeSound()" method of the `Animal` class (via polymorphism) selects `Cat::makeSound()`, resulting in "Meow!".
  i->makeSound();
  j->makeSound();
  meta->makeSound();
  std::cout << "\n";

  delete meta;
  delete j;
  delete i;
  std::cout << "\n";

  //As WrongAnimal::makeSound() is not virtual, it becomes a static binding and the base implementation is always called.
  const WrongAnimal* w = new WrongCat();
  w->makeSound();
  delete w;
  return 0;
}

// ./zoo  
// Animal ctor

// Animal ctor
// Dog ctor
// Animal ctor
// Cat ctor
// Dog ← 
// Cat

// Meow!
// Woof!
// (animal sound)
// Animal dtor
// Dog dtor
// Animal dtor
// Cat dtor
// Animal dtor

// WrongAnimal ctor
// WrongCat ctor
// (wrong animal sound)
// WrongAnimal dtor
