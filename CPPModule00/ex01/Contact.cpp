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
	cout << firstName + "\n";
	cout << lastName + "\n";
	cout << nickname + "\n";
	cout << phoneNumber + "\n";
	cout << darkestSecret + "\n";
}

void Contact::showInfo()
{
	cout << firstName;
}