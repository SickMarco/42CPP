/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:35:09 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/27 18:41:58 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::string name1, name2, name3;
	while (!std::cin.eof())
	{
		std::cout << "Insert ScavTrap name: " << std::flush;
		std::getline(std::cin, name1);
		if (name1.empty())
			continue;
		ScavTrap scav(name1);
		std::cout << "Insert ClapTrap name: " << std::flush;
		std::getline(std::cin, name2);
		if (name2.empty())
			continue;
		ClapTrap clap(name2);
		std::cout << "Insert FragTrap name: " << std::flush;
		std::getline(std::cin, name3);
		if (name3.empty())
			continue;
		FragTrap frag(name3);
		scav.guardGate();
		clap.attack(name1);
		scav.takeDamage(0);
		frag.highFivesGuys();
	}
}