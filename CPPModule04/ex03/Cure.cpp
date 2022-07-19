#include "Cure.hpp"

Cure::Cure(){
    _type = "cure";
}

Cure::Cure(const Cure &a){
    _type = a._type;
}

Cure &Cure::operator=(const Cure &a){
    _type = a._type;
	return *this;
}

Cure::~Cure(){
}

AMateria *Cure::clone() const {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target){
    cout << "* heals " << target.getName() << "'s wounds *\n";
}