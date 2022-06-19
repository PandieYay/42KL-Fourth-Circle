#include "Fixed.hpp"

Fixed::Fixed(){
	_nb = 0;
}

Fixed::Fixed(const Fixed &a){
	_nb = a.getRawBits();
}

Fixed::Fixed(const int a){
	_nb = (a << _bits);
}

Fixed::Fixed(const float a){
	_nb = roundf(a * (1 << _bits));
}

Fixed &Fixed::operator=(const Fixed &a){
    cout << "Copy assignment operator called\n";
	_nb = a.getRawBits();
	return *this;
}

Fixed::~Fixed(){
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

bool Fixed::operator>(const Fixed &obj) const{
	return (toFloat() > obj.toFloat());
}

bool Fixed::operator<(const Fixed &obj) const{
	return (toFloat() < obj.toFloat());
}

bool Fixed::operator>=(const Fixed &obj) const{
	return (toFloat() >= obj.toFloat());
}

bool Fixed::operator<=(const Fixed &obj) const{
	return (toFloat() <= obj.toFloat());
}

bool Fixed::operator==(const Fixed &obj) const{
	return (toFloat() == obj.toFloat());
}

bool Fixed::operator!=(const Fixed &obj) const{
	return (toFloat() != obj.toFloat());
}

Fixed Fixed::operator+(const Fixed &obj){
	return Fixed(toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj){
	return Fixed(toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj){
	return Fixed(toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj){
	return Fixed(toFloat() / obj.toFloat());
}

Fixed Fixed::operator++(){
	Fixed temp;
	temp._nb = ++_nb;
	return (temp);
}

Fixed Fixed::operator++(int){
	Fixed temp;
	temp._nb = _nb++;
	return (temp);
}

float Fixed::min(Fixed a, Fixed b){
	if (a.toFloat() <= b.toFloat())
		return (a.toFloat());
	else
		return (b.toFloat());
}

float Fixed::minConst(const Fixed a, const Fixed b){
	if (a.toFloat() <= b.toFloat())
		return (a.toFloat());
	else
		return (b.toFloat());
}

float Fixed::max(Fixed a, Fixed b){
	if (a.toFloat() >= b.toFloat())
		return (a.toFloat());
	else
		return (b.toFloat());
}

float Fixed::maxConst(const Fixed a, const Fixed b){
	if (a.toFloat() >= b.toFloat())
		return (a.toFloat());
	else
		return (b.toFloat());
}