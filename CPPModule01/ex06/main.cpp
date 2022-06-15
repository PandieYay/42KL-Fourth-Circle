#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl object;

	if (argc != 2)
		return (-1);
	object.complain(argv[1]);
}