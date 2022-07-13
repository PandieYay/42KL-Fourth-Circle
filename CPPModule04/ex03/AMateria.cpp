#include "AMateria.hpp"

AMateria::AMateria(string const &type){
    _type = type;
}

AMateria::AMateria(){
    cout << "AMateria constructor called\n";
}

AMateria::~AMateria(){
    cout << "AMateria destructor called\n";
}

string const &AMateria::getType() const{
    return(_type);
}

void AMateria::use(ICharacter &target){
    (void) target;
}