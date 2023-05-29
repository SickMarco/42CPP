/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:35:09 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/29 12:29:38 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::string name1, name2;
	while (!std::cin.eof())
	{
		std::cout << "Insert ScavTrap name: " << std::flush;
		std::getline(std::cin, name1);
		if (name1.empty())
			continue;
		DiamondTrap dmd(name1);
		std::cout << "Insert ClapTrap name: " << std::flush;
		std::getline(std::cin, name2);
		if (name2.empty())
			continue;
		ClapTrap ctp(name2);
		dmd.whoAmI();
		dmd.attack(name2);
		ctp.takeDamage(30);
	}
}
