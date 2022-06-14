#include "Zombie.hpp"

int	main(void)
{
	int	size;

	Zombie *Daddy;
	size = 20;
	Daddy = zombieHorde(size, "Kerning");
	for (int i = 0; i < size; ++i)
		Daddy[i].announce();
	delete [] Daddy;
}