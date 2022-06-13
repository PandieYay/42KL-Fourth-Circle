#include "Zombie.hpp"

Zombie::Zombie(string name)
{
	_Name = name;
}

Zombie::~Zombie()
{
	cout << _Name << " has died 💀\n";
}

void Zombie::announce(void)
{
	cout << _Name << ": BraiiiiiiinnnzzzZ...\n";
}
