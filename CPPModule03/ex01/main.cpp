#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){
	ClapTrap trap("Bob");
	ScavTrap trap2("Bobby");

	trap2.attack("Bob");
	trap.attack("Bobby");
	trap2.takeDamage(20);
	trap.attack("Bobby");
	trap2.takeDamage(20);
	trap.attack("Bobby");
	trap2.takeDamage(20);
	trap.attack("Bobby");
	trap2.takeDamage(20);
	trap.attack("Bobby");
	trap2.takeDamage(20);
	trap.attack("Bobby");
	trap2.takeDamage(20);
	return 0;
}