#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using std::string;

class Contact {
	private:
		string firstName;
		string lastName;
		string nickname;
		string phoneNumber;
		string darkestSecret;
	public:
		Contact();
		void getInfo();
		void showInfo();
		void showAllInfo();
};

#endif