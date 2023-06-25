/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:16:43 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/25 18:44:36 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
	try
	{
		BitcoinExchange("./data.csv", "./File.txt");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}