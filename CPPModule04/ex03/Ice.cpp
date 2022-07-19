#include "Ice.hpp"

Ice::Ice(){
    _type = "ice";
}


AMateria *Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter &target){
    cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}