#include "ClapTrap.hpp"

void ClapTrap::attack(const string &target){
	if (_hitPoints <= 0)
	{
		cout << _name << " is dead.\n";
		return;
	}
	if (_energyPoints > 0)
	{
		cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!\n";
		--_energyPoints;
	}
	else
		cout << _name << " has no energy left.\n";
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints > 0)
		_hitPoints -= amount;
	else
		cout << _name << " is already dead.\n";
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hitPoints <= 0)
	{
		cout << _name << " is dead.\n";
		return;
	}
	if (_energyPoints > 0)
	{
		cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points back!\n";
		_hitPoints += amount;
		--_energyPoints;
	}
	else
		cout << "Not enough energy.\n";}

ClapTrap::ClapTrap(){
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	cout << "This Constructor called\n";
}

ClapTrap::ClapTrap(string name){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	cout << "Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &a){
	_name = a._name;
	_hitPoints = a._hitPoints;
	_energyPoints = a._energyPoints;
	_attackDamage = a._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a){
	_name = a._name;
	_hitPoints = a._hitPoints;
	_energyPoints = a._energyPoints;
	_attackDamage = a._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(){
	cout << "Destructor called" << endl;
}