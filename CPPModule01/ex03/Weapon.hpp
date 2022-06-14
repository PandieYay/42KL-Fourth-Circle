#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

using std::string;

class Weapon {
	private:
		string _type;
	public:
		Weapon(string type);
		string	const &getType();
		void	setType(string type);
};

#endif