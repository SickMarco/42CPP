#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

std::string trunc(std::string info)
{
	if (info.length() > 10)
	{
		info = info.substr(0, 10);
		info[info.length() - 1] = '.';
	}
	return (info);
}

void PhoneBook::display_contact()
{
	std::string data[4] = {	"Index",
							"First Name",
							"Last Name",
							"Nickname"};

	std::cout << "|";
	for (int i = 0; i < 4; i++)
		std::cout << std::right << std::setw(10) << data[i] << "|";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i + 1 << "|";
		std::cout << std::right << std::setw(10) << trunc(cnt[i].get_contact(0)) << "|";
		std::cout << std::right << std::setw(10) << trunc(cnt[i].get_contact(1)) << "|";
		std::cout << std::right << std::setw(10) << trunc(cnt[i].get_contact(2)) << "|" << std::endl;
	}
}

void PhoneBook::search_contact()
{
	int index = 0;

	std::cout << "Insert Contact Index: ";
	std::cin >> index;
	if (std::cin.fail() || index < 1 || index > 8)
	{
		std::cout << "Invalid Index. Try again." << std::endl;
		return;
	}
	else if (!cnt[index - 1].get_contact(0).empty())
	{
		for (int i = 0; i < 5; i++)
			std::cout << cnt[index - 1].get_contact(i) << std::endl;
	}
}