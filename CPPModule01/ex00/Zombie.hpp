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
		Zombie(string Name);
		~Zombie();
		void announce (void);
};

Zombie *newZombie(string name);
void randomChump (string name);

#endif