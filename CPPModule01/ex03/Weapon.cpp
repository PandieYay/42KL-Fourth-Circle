#include "Weapon.hpp"

Weapon::Weapon(string type)
{
	_type = type;
}

string const &Weapon::getType()
{
	string const &typeREF = _type;
	return (typeREF);
}

void Weapon::setType(string type)
{
	_type = type;
}