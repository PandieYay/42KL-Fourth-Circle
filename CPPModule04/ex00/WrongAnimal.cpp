#include "WrongAnimal.hpp"

string WrongAnimal::getType(void) const{
    return _type;
}

void WrongAnimal::makeSound(void) const{
    cout << "Random animal makes a sound\n";
}

WrongAnimal::WrongAnimal(){
	cout << "WrongAnimal constructor called" << std::endl;
    _type = "Random WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &a){
    _type = a._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a){
    _type = a._type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	cout << "WrongAnimal destructor called" << std::endl;
}