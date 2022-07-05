#include "Dog.hpp"

void Dog::makeSound(void) const{
    cout << "Woof woof bitch\n";
}

Dog::Dog(){
	cout << "Dog constructor called" << std::endl;
    _type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &a){
    _type = a._type;
    brain = new Brain();
}

Dog &Dog::operator=(const Dog &a){
    _type = a._type;
    brain = new Brain();
	return *this;
}

Dog::~Dog(){
	cout << "Dog destructor called" << std::endl;
    delete brain;
}