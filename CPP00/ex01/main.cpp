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
		std::cout << "Insert command: ";
		std::cin >> cmd;
		if (cmd.empty() && std::cin.peek() == '\n')
			continue ;
		if (!cmd.compare("ADD"))
		{
			if (i == 8)
				i = 0;
			phone.cnt[i].set_contact();
			i++;
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