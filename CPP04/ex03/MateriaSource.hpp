//MateriaSource.hpp
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource {
private:
  AMateria* _tmpl[4];
public:
  MateriaSource();
  MateriaSource(MateriaSource const& o);
  MateriaSource& operator=(MateriaSource const& o);
  virtual ~MateriaSource();
  virtual void learnMateria(AMateria* m);
  virtual AMateria* createMateria(std::string const& type);
};
#endif
