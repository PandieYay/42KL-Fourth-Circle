#include "Character.hpp"

int Character::_size = 0;

string const &Character::getName() const{
    return (_name);
}

void Character::equip(AMateria *m){
    if (_size <= 3)
    {
        _inventory[_size] = m;
        ++_size;
    }
}

void Character::unequip(int idx){
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target){
    if (idx >= 0 && idx <= 3)
    if (_inventory[idx] != NULL)
        _inventory[idx]->use(target);
}

Character::Character(string name){
    _name = name;   
}