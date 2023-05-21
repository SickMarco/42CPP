/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:04:04 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/21 20:04:04 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

