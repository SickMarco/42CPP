/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:44:43 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/19 14:30:57 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>

int main()
{
	std::vector<int> num;
	std::list<int> numList;
	int n = 0;
	int find = 0;

	num.reserve(5);
	std::cout << "-- Insert 5 numbers --" << std::endl;
	while (!std::cin.eof())
	{
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Insert num " << i + 1 << ": ";
			std::cin >> n;
			std::cin.ignore(1000, '\n');
			if (std::cin.eof())
				return 0;
			num.push_back(n);
			numList.push_back(n);
		}
		std::cout << "Search number: ";
		std::cin >> find;
		// VECTOR
		if (::easyfind(num, find))
			std::cout << "Found Element in vector" << std::endl;
		else
			std::cout << "Element not found in vector" << std::endl;
		// LIST
		if (::easyfind(numList, find))
			std::cout << "Found Element in list" << std::endl;
		else
			std::cout << "Element not found in list" << std::endl;
	}
	return 0;
}