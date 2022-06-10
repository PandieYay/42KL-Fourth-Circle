#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;

int	main(void)
{
	PhoneBook pb;
	string	str;

	cout << "PhoneBook Time!!!\nADD, SEARCH, or EXIT\n";
	while (1)
	{
		getline(cin, str);
		if (str == "ADD")
			pb.newContact();
		else if (str == "EXIT")
			exit(0);
		else
			cout << "\033[0;31mNot a valid command.\n\033[0m";
	}
	pb.showAllContacts();
}