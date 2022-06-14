#include "HumanB.hpp"
#include <iostream>

using std::cout;

HumanB::HumanB(string name)
{
	_name = name;
}

void HumanB::attack()
{
	cout << _name << " attacks with their " << _weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}