/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:44:43 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/15 14:01:47 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>

int main()
{
	std::vector<int> num;
	int n = 0;
	int find = 0;

	std::cout << "-- Insert 5 numbers --" << std::endl;
	while (!std::cin.eof())
	{
		for (int i = 0; i < 5; i++)
		{
			if (std::cin.eof())
				return 0;
			std::cout << "Insert num " << i + 1 << ": ";
			std::cin >> n;
			std::cin.ignore(1000, '\n');
			num.push_back(n);
		}
		std::cout << "Search number: ";
		std::cin >> find;
		if (::easyfind<std::vector<int>, int>(num, find))
			std::cout << "Found Element" << std::endl;
		else
			std::cout << "Element not found" << std::endl;
	}
	return 0;
}