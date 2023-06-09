/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:01 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 14:48:56 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::string name;
	int grade;

	while (!std::cin.eof())
	{
		std::cout << "Insert Bureaucrat Name: ";
		std::getline(std::cin, name);
		if (name.empty())
			continue;
		std::cout << "Insert Bureaucrat Grade: ";
		std::cin >> grade;
		std::cin.ignore(1000, '\n');

		try {
			Bureaucrat b(name, grade);
			std::cout << b << "You get a promotion!" << std::endl; 
			b.promotion();
			std::cout << b;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}