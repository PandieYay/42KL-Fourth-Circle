#include "PhoneBook.hpp"
#include <iostream>

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
	int	i;

	i = 0;
	while (i < index)
	{
		Contacts[i].showInfo();
		i++;
	}
}