#include <iostream>
#include <cctype>

using std::cout;
using std::endl;

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (-1);
	}
	i = 1;
	while (argv[i] != 0)
	{
		for (size_t k = 0; k < strlen(argv[i]); ++k)
			cout << (char)toupper(argv[i][k]);
		++i;
	}
	cout << endl;
}