#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::new_contact(Contact *cnt, int i)
{
	cnt[i].set_fName();
	cnt[i].set_lName();
	cnt[i].set_nName();
	cnt[i].set_numb();
	cnt[i].set_secret();
	if (!cnt[i].check_field())
	{
		std::cout << "\033[0;31mError: Empty Field\033[0;37m" << std::endl;
		cnt[i].reset_contact();
	}
}