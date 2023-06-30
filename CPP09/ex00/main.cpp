/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:16:43 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/30 16:02:40 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		const std::string database = "./data.csv";
		const std::string list = av[1];
		try{
			BitcoinExchange btc(database, list);
			btc.exchanger();
		}
		catch(const std::exception& e){ std::cerr << e.what() << std::endl; }
	}
	else
		std::cerr << "Insert database file" << std::endl;
	return 0;
}