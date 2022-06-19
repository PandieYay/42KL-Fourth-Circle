#include "Fixed.hpp"

Fixed::Fixed(){
	_nb = 0;
    cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &a){
    cout << "Copy constructor called\n";
	_nb = a.getRawBits();
}

Fixed::Fixed(const int a){
	_nb = (a << _bits);
	cout << "Int constructor called\n";
}

Fixed::Fixed(const float a){
	_nb = roundf(a * (1 << _bits));
	cout << "Float constructor called\n";
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
	return (_nb);
}

void Fixed::setRawBits(int const raw){
	_nb = raw;
}

float Fixed::toFloat(void) const{
	return ((float)_nb / (float)(1 << _bits));
}

int	Fixed::toInt(void) const{
	return (_nb >> _bits);
}

ostream& operator<<(ostream& os, const Fixed &dt)
{
    os << dt.toFloat();
    return os;
}