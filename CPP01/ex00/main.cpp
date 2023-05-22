/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:04:21 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/22 15:32:53 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string input;
	std::string newName;
	char		mem;
	
	std::cout 	<< "\e[1;31m ---WELCOME IN THE ZOMBIE FACTORY--- " << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "\e[0;37mSelect the zombie maker (Heap or Stack) [H/S]: ";
		std::getline(std::cin, input);
		mem = std::toupper(input[0]);
		if (input.length() != 1 || (mem != 'H' && mem != 'S'))
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