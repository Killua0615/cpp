//Brain.hpp
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
  std::string ideas[100];
public:
  Brain();
  Brain(const Brain& o);
  Brain& operator=(const Brain& o);
  ~Brain();

  const std::string& getIdea(int i) const;
  void setIdea(int i, const std::string& s);
};
#endif
