#include "DiamondTrap.hpp"

void DiamondTrap::attack(const string &target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void){
	cout << "I am " << _name << " and I am also " << ClapTrap::_name << "\n";
}

DiamondTrap::DiamondTrap(string name)
{
	cout << "DiamondTrap constructor called\n";
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	ClapTrap::_name = _name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &a)
{
	*this = a;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &a){
	_name = a._name;
	_hitPoints = a._hitPoints;
	_energyPoints = a._energyPoints;
	_attackDamage = a._attackDamage;
	ClapTrap::_name = _name + "_clap_name";
	return *this;
}

DiamondTrap::~DiamondTrap(){
	cout << "DiamondTrap destructor called\n";
}