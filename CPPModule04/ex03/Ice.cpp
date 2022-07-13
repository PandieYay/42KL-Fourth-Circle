#include "Ice.hpp"

AMateria *Ice::clone() const {
    AMateria *tmp;
    tmp = NULL;
    return (tmp);
}

void Ice::use(ICharacter &target){
    cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}