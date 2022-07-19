#include "AMateria.hpp"

AMateria::AMateria(string const &type){
    _type = type;
}

AMateria::AMateria(){
}

AMateria::AMateria(const AMateria &a){
    _type = a._type;
}

AMateria &AMateria::operator=(const AMateria &a){
    _type = a._type;
	return *this;
}

AMateria::~AMateria(){
}

string const &AMateria::getType() const{
    return(_type);
}

void AMateria::use(ICharacter &target){
    (void) target;
}