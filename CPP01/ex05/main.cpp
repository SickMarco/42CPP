#include "Harl.hpp"

int main()
{
	std::string cmd;
	Harl Harlem;

	while (!std::cin.eof())
	{
		std::cout << "Insert cmd: ";
		std::getline(std::cin, cmd);
		Harlem.complain(cmd);
	}
	return 0;
}