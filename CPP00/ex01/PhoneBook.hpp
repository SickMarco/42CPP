#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
public:
	Contact cnt[8];

	PhoneBook();
	~PhoneBook();
	void new_contact(Contact *cnt, int index);
};

#endif