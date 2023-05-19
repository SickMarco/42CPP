#include "Zombie.hpp"

int main()
{
	std::string newName;
	char		mem;
	
	std::cout 	<< "\e[1;31m ---WELCOME IN THE ZOMBIE FACTORY--- " << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "\e[0;37mSelect the zombie maker (Heap or Stack) [H/S]: ";
		std::cin >> mem;
		if (std::cin.eof())
			break;
		std::cin.ignore(1000, '\n');
		mem = std::toupper(mem);
		if (mem != 'H' && mem != 'S')
            continue;
		std::cout << "Insert zombie name: " << std::flush;
		if (!std::getline(std::cin, newName))
			continue;
		switch (mem) 
		{
			case 'H':
				{
					Zombie *z = newZombie(newName);
					z->announce();
					delete z;
				}
				break;
			case 'S':
			{
				randomChump(newName);
			}
				break;
			default:
				break;
		}
	}
	return 0;
}