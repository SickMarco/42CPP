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
		info[9] = '.';
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
		std::cout << std::right << std::setw(10) << trunc(cnt[i].get_info(0)) << "|";
		std::cout << std::right << std::setw(10) << trunc(cnt[i].get_info(1)) << "|";
		std::cout << std::right << std::setw(10) << trunc(cnt[i].get_info(2)) << "|" << std::endl;
	}
}

void PhoneBook::search_contact()
{
	std::string data[5] = {	"First Name",
						"Last Name",
						"Nickname",
						"Number",
						"Secret"};

	int index = 0;
	std::string tmp;
	std::cout << "Insert Contact Index: ";
	std::getline(std::cin, tmp);
	index = atoi(tmp.c_str());
	if (index < 1 || index > 8)
		std::cout << "Invalid Index. Search again." << std::endl;
	else if (!cnt[index - 1].get_info(0).empty())
		for (int i = 0; i < 5; i++)
			std::cout << data[i] << ": " << cnt[index - 1].get_info(i) << std::endl;
}