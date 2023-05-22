/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:35:29 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/22 14:53:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	std::string levels[] = {"DEBUG",
						  "INFO",
						  "WARNING",
						  "ERROR"};
	Harl Harlem;

	if (ac == 2)
	{
		std::string cmd = av[1];
		int i;
		for(i = 0; i < 4; i++)
		{
			if (!levels[i].compare(cmd))
			{
				switch (i)
				{
				case 0:
					Harlem.complain(levels[0]);
				case 1:
					Harlem.complain(levels[1]);
				case 2:
					Harlem.complain(levels[2]);
				case 3:
					Harlem.complain(levels[3]);
					return 0;
				}
			}
		}
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	std::cout << "Wrong arguments number" << std::endl;
	return 1;
}