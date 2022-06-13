#include "Zombie.hpp"

int	main(void)
{
	Zombie *Daddy;
	Daddy = newZombie("Hyun-Zge");
	Daddy->announce();
	delete Daddy;
	randomChump("Wallace");
	Daddy = newZombie("Mooma");
	delete Daddy;
}