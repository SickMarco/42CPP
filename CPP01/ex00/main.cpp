#include "Zombie.hpp"

int main()
{
	std::string newName;
	char		mem;
	
	std::cout 	<< "\e[1;31m ---WELCOME IN THE ZOMBIE FACTORY--- " << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "\e[0;37mSelect the zombie maker (Heap or Stack) [H/S]: ";
		std::cin.get(mem);
		std::cin.ignore(100, '\n');
		if (std::cin.eof())
			break;
		mem = std::toupper(mem);
		if (mem != 'H' && mem != 'S')
            continue;
		std::cout << "Insert zombie name: " << std::flush;
		std::getline(std::cin, newName);
		if (newName.empty())
			continue;
		switch (mem) 
		{
			case 'H':
			{
				Zombie *z = newZombie(newName);
				z->announce();
				delete z;
				break;
			}
			case 'S':
				randomChump(newName);
				break;

			default:
				break;
		}
	}
	return 0;
}