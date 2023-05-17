#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_fName()
{
	std::cout << "Insert First Name: ";
	std::getline(std::cin, this->fName);
}

void Contact::set_lName()
{
	std::cout << "Insert Last Name: ";
	std::getline(std::cin, this->lName);
}

void Contact::set_nName()
{
	std::cout << "Insert Nickame: ";
	std::getline(std::cin, this->nName);
}

void Contact::set_numb()
{
	std::cout << "Insert Number: ";
	std::getline(std::cin, this->numb);
}

void Contact::set_secret()
{
	std::cout << "Insert Secret: ";
	std::getline(std::cin, this->Secret);
}

bool Contact::check_field()
{
	return (!fName.empty() && !lName.empty() && !nName.empty() && !numb.empty() && !Secret.empty());
}

void Contact::reset_contact()
{
	fName.clear();
	lName.clear();
	nName.clear();
	numb.clear();
	Secret.clear();
}