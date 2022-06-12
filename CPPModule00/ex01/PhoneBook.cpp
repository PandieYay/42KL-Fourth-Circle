#include "PhoneBook.hpp"
#include <iostream>

using std::cout;
using std::cin;

PhoneBook::PhoneBook()
{
	index = 0;
}

void PhoneBook::newContact()
{
	Contacts[index].getInfo();
	++index;
}

void PhoneBook::showAllContacts()
{
	int	input;
	int	i;

	if (index == 0)
	{
		cout << "No contacts...\n";
		return ;
	}
	cout << "|==========|==========|==========|==========|\n";
	cout << "|     Index|First Name| Last Name| Nick Name|\n";
	cout << "|==========|==========|==========|==========|\n";
	i = 0;
	while (i < index)
	{
		cout << "|         " << i << "|";
		Contacts[i].showInfo();
		cout << "|==========|==========|==========|==========|\n";
		i++;
	}
	cout << "Please enter an index number\n";
	cin >> input;
	if (!cin)
	{
		cin.clear();
		return ;	
	}
	if (input < index && input >= 0)
	{
		cout << "|==========|==========|==========|==========|==========|==========|\n";
		cout << "|     Index|First Name| Last Name| Nick Name| Phone No |  Secret  |\n";
		cout << "|==========|==========|==========|==========|==========|==========|\n";
		cout << "|         " << input << "|";
		Contacts[input].showAllInfo();
		cout << "|==========|==========|==========|==========|==========|==========|\n";
		cout << "Commands available: ADD, SEARCH, or EXIT\n";
		cin.ignore();
	}
	return ;
}