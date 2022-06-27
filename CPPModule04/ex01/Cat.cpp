#include "Cat.hpp"
#include "Brain.hpp"

void Cat::makeSound(void) const{
    cout << "Meow meow UWU\n";
}

Cat::Cat(){
	cout << "Cat constructor called" << std::endl;
    _type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &a){
    _type = a._type;
    brain = new Brain();
}

Cat &Cat::operator=(const Cat &a){
    _type = a._type;
    brain = new Brain();
	return *this;
}

Cat::~Cat(){
	cout << "Cat destructor called" << std::endl;
    delete brain;
}