#include "Harl.hpp"

void Harl::debug(void)
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void)
{
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::nothing(void)
{
	cout << "[ Probably complaining about insignificant problems ]\n";
}
void Harl::complain(string level)
{
	int	i;
	string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	i = 0;
	while (i < 4 && level != levels[i])
		i++;
	switch(i) {
		case(0):
			debug();
		case(1):
			info();
		case(2):
			warning();
		case(3):
			error();
			break;
		default:
			nothing();
	}
}