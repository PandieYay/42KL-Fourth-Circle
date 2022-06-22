#include "ScavTrap.hpp"

void ScavTrap::attack(const string &target){
	if (_hitPoints <= 0)
	{
		cout << _name << " is dead.\n";
		return;
	}
	if (_energyPoints > 0)
	{
		cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!\n";
		--_energyPoints;
	}
	else
		cout << _name << " has no energy left.\n";
}

void ScavTrap::guardGate(void){
	cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}

ScavTrap::ScavTrap(){
	cout << "ScavTrap Constructor called\n";
}

ScavTrap::ScavTrap(string name): ClapTrap(name)
{
	cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &a)
{
	*this = a;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &a){
	_name = a._name;
	_hitPoints = a._hitPoints;
	_energyPoints = a._energyPoints;
	_attackDamage = a._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap(){
	cout << "ScavTrap destructor called\n";
}