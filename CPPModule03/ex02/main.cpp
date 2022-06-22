#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){
	ClapTrap trap("Bob");
	FragTrap trap2("Bobby");

	trap2.highFiveGuys();
	trap2.attack("Bob");
	trap.takeDamage(30);
	trap2.attack("Bob");
	trap.takeDamage(30);
	trap2.attack("Bob");
	trap.takeDamage(30);
	trap2.attack("Bob");
	trap.takeDamage(30);
	trap2.attack("Bob");
	trap.takeDamage(30);
	return 0;
}