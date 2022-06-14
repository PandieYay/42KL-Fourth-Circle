#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

using std::string;

class HumanB {
	private:
		Weapon *_weapon;
		string _name;
	public:
		HumanB(string name);
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif