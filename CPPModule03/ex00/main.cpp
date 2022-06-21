#include "ClapTrap.hpp"

int	main(void){
	ClapTrap trap("Bob");
	ClapTrap trap2("Bobby");


	trap.attack("Bobby");
	trap2.takeDamage(5);
	trap2.attack("Bob");
	trap.takeDamage(10);
	trap.beRepaired(10);
	trap2.attack("Bobby");
	trap.takeDamage(10);

	trap2.beRepaired(5);
	trap2.attack("Bobby");
	trap2.attack("Bobby");
	trap2.attack("Bobby");
	trap2.attack("Bobby");
	trap2.attack("Bobby");
	trap2.attack("Bobby");
	trap2.attack("Bobby");
	trap2.attack("Bobby");
	return 0;
}