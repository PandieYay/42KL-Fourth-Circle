#include "Character.hpp"

string const &Character::getName() const{
    return (_name);
}

void Character::equip(AMateria *m){
    _inventory[0] = m;
}

void Character::unequip(int idx){
    delete _inventory[idx];
}

void Character::use(int idx, ICharacter &target){
    (void)target;
    if (_inventory[idx] != NULL)
        _inventory[idx]->use(target);
}

Character::Character(string name){
    _name = name;   
}