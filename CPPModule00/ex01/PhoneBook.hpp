#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact Contacts[8];
		int		index;
	public:
		PhoneBook();
		void	newContact();
		void	showAllContacts();
};

#endif