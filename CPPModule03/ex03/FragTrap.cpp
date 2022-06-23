#include "FragTrap.hpp"

void FragTrap::attack(const string &target){
	if (_hitPoints <= 0)
	{
		cout << _name << " is dead.\n";
		return;
	}
	if (_energyPoints > 0)
	{
		cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!\n";
		--_energyPoints;
	}
	else
		cout << _name << " has no energy left.\n";
}

void FragTrap::highFiveGuys(void){
	cout << "FragTrap " << _name << ": High Five guys!\n";
}

FragTrap::FragTrap(){
	cout << "FragTrap Constructor called\n";
	_attackDamage = 30;
}

FragTrap::FragTrap(string name): ClapTrap(name)
{
	cout << "FragTrap with string constructor called\n";
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &a)
{
	*this = a;
}

FragTrap &FragTrap::operator=(const FragTrap &a){
	_name = a._name;
	_hitPoints = a._hitPoints;
	_energyPoints = a._energyPoints;
	_attackDamage = a._attackDamage;
	return *this;
}

FragTrap::~FragTrap(){
	cout << "FragTrap destructor called\n";
}