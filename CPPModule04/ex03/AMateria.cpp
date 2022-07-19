#include "AMateria.hpp"

AMateria::AMateria(string const &type){
    _type = type;
}

AMateria::AMateria(){
}

AMateria::~AMateria(){
}

string const &AMateria::getType() const{
    return(_type);
}

void AMateria::use(ICharacter &target){
    (void) target;
}