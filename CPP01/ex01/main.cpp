#include "Zombie.hpp"

int main()
{
	std::string newName;
	int horde = 0;
	Zombie *ptr = NULL;
	
	std::cout 	<< "\e[1;31m ---WELCOME IN THE ZOMBIE HORDE FACTORY--- " << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "\e[0;37mInsert Horde troop load:";
		while (!(std::cin >> horde))
		{
			if (std::cin.eof())
				return 1;
        	std::cout << "Invalid input. Please enter an integer: ";
       		std::cin.clear();
        	std::cin.ignore(1000, '\n');
   		}
		std::cin.ignore(1000, '\n');
		std::cout << "Insert zombie name: " << std::flush;
		std::getline(std::cin, newName);
		if (newName.empty())
			continue;
		ptr = zombieHorde(horde, newName);
		delete[] ptr;
	}
	return 0;
}

