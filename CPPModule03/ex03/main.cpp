#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void){
	ClapTrap trap("Bob");
	DiamondTrap trap2("Bobby");

	//show off special functions
	trap2.guardGate();
	trap2.highFiveGuys();
	trap2.whoAmI();

	//Bobby attacks
	trap2.attack("Bob");
	trap.takeDamage(30);

	//ClapTrap attacks Bob and kills him
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

	//final blow
	trap.attack("Bobby");
	trap2.takeDamage(20);
	return 0;
}