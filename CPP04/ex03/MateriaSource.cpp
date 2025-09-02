//MateriaSource.cpp
#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
  int i=0; while(i<4){ _tmpl[i]=0; ++i; }
}
MateriaSource::MateriaSource(MateriaSource const& o){
  int i=0; while(i<4){ _tmpl[i]=0; ++i; }
  i=0; while(i<4){ if(o._tmpl[i]) _tmpl[i]=o._tmpl[i]->clone(); ++i; }
}
MateriaSource& MateriaSource::operator=(MateriaSource const& o){
  if(this!=&o){
    int i=0; while(i<4){ if(_tmpl[i]){ delete _tmpl[i]; _tmpl[i]=0; } ++i; }
    i=0; while(i<4){ if(o._tmpl[i]) _tmpl[i]=o._tmpl[i]->clone(); ++i; }
  }
  return *this;
}
MateriaSource::~MateriaSource(){
  int i=0; while(i<4){ if(_tmpl[i]) delete _tmpl[i]; ++i; }
}
void MateriaSource::learnMateria(AMateria* m){
  if(!m) return;
  int i=0; while(i<4 && _tmpl[i]) ++i;
  if(i<4) _tmpl[i]=m; else delete m;
}
AMateria* MateriaSource::createMateria(std::string const& type){
  int i=0; while(i<4){
    if(_tmpl[i] && _tmpl[i]->getType()==type) return _tmpl[i]->clone();
    ++i;
  }
  return 0;
}
