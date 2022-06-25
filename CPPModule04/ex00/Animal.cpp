#include "Animal.hpp"

string Animal::getType(void) const{
    return _type;
}

void Animal::makeSound(void) const{
    cout << "Random animal makes a sound\n";
}

Animal::Animal(){
	cout << "Animal constructor called" << std::endl;
    _type = "Random Animal";
}

Animal::Animal(const Animal &a){
    _type = a._type;
}

Animal &Animal::operator=(const Animal &a){
    _type = a._type;
	return *this;
}

Animal::~Animal(){
	cout << "Animal destructor called" << std::endl;
}