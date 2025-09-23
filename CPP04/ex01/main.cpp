//main.cpp
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() { //Alternate between Dog and Cat
  const int N = 4;
  Animal* a[N];

  int i = 0;
  while (i < N)
  {
    if (i % 2 == 0) {
      a[i] = static_cast<Animal*>(new Dog());
    }
    else {
      a[i] = static_cast<Animal*>(new Cat());
    }
    ++i;
  }
  std::cout << "\n";

  std::cout << "-----START DITOR-----\n";
  i = 0;
  while (i < N) {
    delete a[i];
    ++i;
  }
  std::cout << "\n";

  std::cout << "-----COPY CTOR-----\n";
  Dog d1;
  d1.getBrain()->setIdea(0, "meat");
  Dog d2 = d1; 
  d1.getBrain()->setIdea(0, "fish");
  std::cout << "\n";

  std::cout << "----- SWITCH -----\n";
  std::cout << "d1:" << d1.getBrain()->getIdea(0) << std::endl;
  std::cout << "d2:" << d2.getBrain()->getIdea(0) << "\n" << std::endl;

  return 0;
}

