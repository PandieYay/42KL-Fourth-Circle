#include "Cure.hpp"

AMateria *Cure::clone() const {
    AMateria *tmp;
    tmp = NULL;
    return (tmp);
}

void Cure::use(ICharacter &target){
    cout << "* heals " << target.getName() << "'s wounds *\n";
}