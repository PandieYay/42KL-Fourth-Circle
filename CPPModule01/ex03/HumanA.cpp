#include "HumanA.hpp"
#include <iostream>

using std::cout;

HumanA::HumanA(string name, Weapon &weapon) : _weapon(weapon)
{
	_name = name;
}

void HumanA::attack()
{
	cout << _name << " attacks with their " << _weapon.getType() << "\n";
}