//Brain.cpp
#include "Brain.hpp"

Brain::Brain() {}
Brain::Brain(const Brain& o){ int i=0; while(i<100){ ideas[i]=o.ideas[i]; ++i; } }
Brain& Brain::operator=(const Brain& o){ if(this!=&o){ int i=0; while(i<100){ ideas[i]=o.ideas[i]; ++i; } } return *this; }
Brain::~Brain() {}

const std::string& Brain::getIdea(int i) const { return ideas[i]; }
void Brain::setIdea(int i, const std::string& s){ ideas[i]=s; }
