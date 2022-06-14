#include "Zombie.hpp"

Zombie *zombieHorde(int n, string name)
{
	Zombie	*Mommy = new Zombie[n];
	for (int i = 0; i < n; ++i)
		Mommy[i].setname(name);
	return (Mommy);
}