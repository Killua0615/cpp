//Brain.hpp
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
  std::string ideas[100]; //The premise that one can remember 100 ideas
public:
  Brain();
  Brain(const Brain& o);
  Brain& operator=(const Brain& o);
  ~Brain();
  const std::string& getIdea(int i) const;

  void setIdea(int i, const std::string& s);
};
#endif
