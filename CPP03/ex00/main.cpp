/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:35:09 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/26 12:53:11 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	std::string name1, name2;
	while (!std::cin.eof())
	{
		std::cout << "Insert attacker name: ";
		std::getline(std::cin, name1);
		if (name1.empty())
			continue;
		ClapTrap att(name1);
		std::cout << "Insert defender name: ";
		std::getline(std::cin, name2);
		if (name2.empty())
			continue;
		ClapTrap def(name2);
		att.attack(name2);
		def.takeDamage(5);
		def.beRepaired(5);
	}
}