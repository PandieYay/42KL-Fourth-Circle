#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	cout << _Name << " has died 💀\n";
}

void Zombie::setname(string name)
{
	_Name = name;
}

void Zombie::announce(void)
{
	cout << _Name << ": BraiiiiiiinnnzzzZ...\n";
}
