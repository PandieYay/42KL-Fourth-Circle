#include "Cure.hpp"

Cure::Cure(){
    _type = "cure";
}

AMateria *Cure::clone() const {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target){
    cout << "* heals " << target.getName() << "'s wounds *\n";
}