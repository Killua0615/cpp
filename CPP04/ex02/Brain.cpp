#include "Brain.hpp"

Brain::Brain(){ std::cout << "Brain ctor\n"; }
Brain::Brain(const Brain& o) {
  int i = 0;
  while (i < 100) { ideas[i] = o.ideas[i]; ++i; }
  std::cout << "Brain copy ctor\n";
}
Brain& Brain::operator=(const Brain& o) {
  if (this != &o) {
    int i = 0;
    while (i < 100) { ideas[i] = o.ideas[i]; ++i; }
  }
  std::cout << "Brain copy assign\n";
  return *this;
}
Brain::~Brain() { std::cout << "Brain dtor\n"; }

const std::string& Brain::getIdea(int i) const { return ideas[i]; }
void Brain::setIdea(int i, const std::string& s) { ideas[i] = s; }
//ideas is an array of type std::string ideas[100];
//The string s is **assigned (overwritten)** to the element specified by the argument i (ideas[i]).
//s is received as const std::string&, and within the function, a copy of the string occurs at the point where ideas[i] = s;
