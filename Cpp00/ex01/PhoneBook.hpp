#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	Contact contacts[8];
	int index;

  public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();
};

#endif