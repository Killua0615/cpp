//Character.cpp
#include "Character.hpp"
#include <cstddef>

Character::Character(std::string const& name) : _name(name), _floorCount(0){
  int i=0; while(i<4){ _inv[i]=0; ++i; }
  i=0; while(i<128){ _floor[i]=0; ++i; }
}
Character::Character(Character const& o) : _name(o._name), _floorCount(0){
  int i=0; while(i<4){ _inv[i]=0; ++i; }
  i=0; while(i<128){ _floor[i]=0; ++i; }
  cloneFrom(o);
}
Character& Character::operator=(Character const& o){
  if(this!=&o){
    _name=o._name;
    clearInv();
    cloneFrom(o);
  }
  return *this;
}
Character::~Character(){
  clearInv();
  int i=0; while(i<_floorCount){ delete _floor[i]; ++i; }
}
void Character::clearInv(){
  int i=0; while(i<4){ if(_inv[i]){ delete _inv[i]; _inv[i]=0; } ++i; }
}
void Character::cloneFrom(Character const& o){
  int i=0; while(i<4){ if(o._inv[i]) _inv[i]=o._inv[i]->clone(); else _inv[i]=0; ++i; }
}
std::string const& Character::getName() const { return _name; }
void Character::equip(AMateria* m){
  if(!m) return;
  int i=0; while(i<4 && _inv[i]) ++i;
  if(i<4) _inv[i]=m;
}
void Character::unequip(int idx){
  if(idx<0 || idx>=4) return;
  if(!_inv[idx]) return;
  if(_floorCount<128){ _floor[_floorCount++]=_inv[idx]; }
  _inv[idx]=0;
}
void Character::use(int idx, ICharacter& target){
  if(idx<0 || idx>=4) return;
  if(_inv[idx]) _inv[idx]->use(target);
}
