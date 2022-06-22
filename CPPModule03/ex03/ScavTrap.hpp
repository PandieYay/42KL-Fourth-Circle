#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(string name);
		ScavTrap(const ScavTrap &a);
		ScavTrap &operator = (const ScavTrap &a);
		~ScavTrap();
		void attack(const string &target);
		void guardGate(void);
};

#endif