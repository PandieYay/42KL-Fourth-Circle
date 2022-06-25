#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(string name);
		FragTrap(const FragTrap &a);
		FragTrap &operator = (const FragTrap &a);
		~FragTrap();
		void attack(const string &target);
		void highFiveGuys(void);
};

#endif