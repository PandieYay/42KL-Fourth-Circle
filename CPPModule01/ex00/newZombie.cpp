#include "Zombie.hpp"

Zombie *newZombie(string name)
{
	Zombie	*Mommy = new Zombie(name);
	return (Mommy);
}