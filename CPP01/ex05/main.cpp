/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:36:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/21 19:36:25 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	std::string cmd;
	Harl Harlem;

	while (!std::cin.eof())
	{
		std::cout << "Insert cmd: ";
		std::getline(std::cin, cmd);
		if(!cmd.empty())
			Harlem.complain(cmd);
	}
	return 0;
}