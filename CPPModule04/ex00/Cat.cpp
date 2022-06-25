#include "Cat.hpp"

void Cat::makeSound(void) const{
    cout << "Meow meow UWU\n";
}

Cat::Cat(){
	cout << "Cat constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &a){
    _type = a._type;
}

Cat &Cat::operator=(const Cat &a){
    _type = a._type;
	return *this;
}

Cat::~Cat(){
	cout << "Cat destructor called" << std::endl;
}