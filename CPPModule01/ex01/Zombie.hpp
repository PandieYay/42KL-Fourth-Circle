#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
using std::cout;
using std::string;

class Zombie {
	private:
		string _Name;
	public:
		Zombie();
		~Zombie();
		void setname (string name);
		void announce (void);
};

Zombie *zombieHorde(int n, string name);

#endif