#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
public:
	Contact cnt[8];

	PhoneBook();
	~PhoneBook();
	void display_contact();
	void search_contact();
};

#endif