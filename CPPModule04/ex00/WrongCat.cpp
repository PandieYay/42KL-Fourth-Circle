#include "WrongCat.hpp"

void WrongCat::makeSound(void) const{
    cout << "Meow meow UWU\n";
}

WrongCat::WrongCat(){
	cout << "WrongCat constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &a){
    _type = a._type;
}

WrongCat &WrongCat::operator=(const WrongCat &a){
    _type = a._type;
	return *this;
}

WrongCat::~WrongCat(){
	cout << "WrongCat destructor called" << std::endl;
}