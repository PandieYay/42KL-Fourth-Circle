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

Character::Character(const Character &a){
    _name = a._name;
    for (int i = 0; a._inventory[i] != NULL; i++)
        _inventory[i] = a._inventory[i];
    _size = a._size;
}

Character &Character::operator=(const Character &a){
    _name = a._name;
    for (int i = 0; a._inventory[i] != NULL; i++)
        _inventory[i] = a._inventory[i];
    _size = a._size;
	return *this;
}

Character::~Character(){
    for (int i = 0; _inventory[i] != NULL; i++)
        delete _inventory[i];
}