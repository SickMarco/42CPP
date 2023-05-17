#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phone;
	Contact contact;
	std::string cmd;
	static int i = 0;

	std::cout << "\033[1;32m--- Welcome " << std::getenv("USER") << " ---\033[0m" <<std::endl;
	while (std::cout << "Insert command: " && std::getline(std::cin, cmd))
	{
		if (!cmd.compare("ADD"))
		{
			if (i == 8)
				i = 0;
			phone.new_contact(phone.cnt, i);
			i++;
		}
		// else if ((!cmd.compare("SEARCH")))
		else if (!cmd.compare("EXIT"))
			break;
	}
	return 0;
}