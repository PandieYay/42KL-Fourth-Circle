#include "ScavTrap.hpp"

ScavTrap::ScavTrap(string name): ClapTrap(name)
{
	cout << "ScavTrap constructor called\n";
}

ScavTrap::~ScavTrap(){
	cout << "ScavTrap destructor called\n";
}