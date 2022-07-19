#include "Ice.hpp"

Ice::Ice(){
    _type = "ice";
}

Ice::Ice(const Ice &a){
    _type = a._type;
}

Ice &Ice::operator=(const Ice &a){
    _type = a._type;
	return *this;
}

Ice::~Ice(){
}

AMateria *Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter &target){
    cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}