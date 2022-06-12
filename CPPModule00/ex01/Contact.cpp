#include "Contact.hpp"
#include <iostream>

using std::cout;
using std::string;
using std::cin;

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

void Contact::getInfo()
{
	string	str;

	cout << "First Name:\n";
	getline(cin, str);
	firstName = str;
	cout << "Last Name:\n";
	getline(cin, str);
	lastName = str;
	cout << "Nickname:\n";
	getline(cin, str);
	nickname = str;
	cout << "Phone Number:\n";
	getline(cin, str);
	phoneNumber = str;
	cout << "Darkest Secret:\n";
	getline(cin, str);
	darkestSecret = str;
	cout << "Done! Contact added\n";
	cout << "Commands available: ADD, SEARCH, or EXIT\n";
}

static void	displaysearch(string text)
{
	if (text.length() <= 10)
	{
		for (int i = 0; i + text.length() < 10; ++i)
		{
			cout << " ";
		}
		cout << text;
	}
	else
		cout << text.substr(0, 9) << ".";
	cout << "|";
}

void Contact::showInfo()
{
	displaysearch(firstName);
	displaysearch(lastName);
	displaysearch(nickname);
	cout << "\n";
}

void Contact::showAllInfo()
{
	displaysearch(firstName);
	displaysearch(lastName);
	displaysearch(nickname);
	displaysearch(phoneNumber);
	displaysearch(darkestSecret);
	cout << "\n";
}
