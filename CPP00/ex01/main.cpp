#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phone;
	std::string cmd;
	static int i = 0;

	std::cout << "\033[1;32m--- Welcome " << std::getenv("USER") << " ---\033[0m" <<std::endl;
	while (!std::cin.eof())
	{
		std::cout << "Insert command: " ; 
		std::getline(std::cin, cmd);
		if (!cmd.compare("ADD"))
		{
			phone.cnt[i].set_contact();
			(i == 7) ? i = 0 : i++;
		}
		else if (!cmd.compare("SEARCH"))
		{
			phone.display_contact();
			phone.search_contact();
		}
		else if (!cmd.compare("EXIT"))
			break;
	}
	return 0;
}