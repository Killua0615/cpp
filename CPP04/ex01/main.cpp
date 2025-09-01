//main.cpp
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(){
  const int N=4;
  Animal* a[N];
  int i=0; while(i<N){ a[i]=(i%2==0)? static_cast<Animal*>(new Dog()) : static_cast<Animal*>(new Cat()); ++i; }
  i=0; while(i<N){ delete a[i]; ++i; }

  Dog d1; d1.getBrain()->setIdea(0,"meat");
  Dog d2=d1;
  d1.getBrain()->setIdea(0,"fish");
  std::cout << "d1:" << d1.getBrain()->getIdea(0) << std::endl;
  std::cout << "d2:" << d2.getBrain()->getIdea(0) << std::endl;
  return 0;
}
