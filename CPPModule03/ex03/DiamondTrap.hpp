#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class DiamondTrap: public FragTrap, public ScavTrap {
	private:
		string _name;
	public:
		DiamondTrap(string name);
		DiamondTrap(const DiamondTrap &a);
		DiamondTrap &operator = (const DiamondTrap &a);
		~DiamondTrap();
		void attack(const string &target);
		void whoAmI(void);
};
#endif