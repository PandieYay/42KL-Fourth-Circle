#include "Fixed.hpp"

Fixed::Fixed(){
	_nb = 0;
    cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &a){
    cout << "Copy constructor called\n";
	_nb = a.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &a){
    cout << "Copy assignment operator called\n";
	_nb = a.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const{
	cout << "getRawBits member function called\n";
	return (_nb);
}

void Fixed::setRawBits(int const raw){
	_nb = raw;
}