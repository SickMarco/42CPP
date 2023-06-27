/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:01:00 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/27 15:32:28 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::string argvToStr(int ac, char **av){
	std::string str;
    for (int i = 1; i < ac; ++i){
        str += av[i];
        if (i < ac - 1){
            str += ' ';
        }
    }
	return str;
}

int main(int ac, char **av)
{
	if (ac > 1){
		try
		{
			PmergeMe numbers(argvToStr(ac, av));
			numbers.order();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cerr << "Insert number list" << std::endl;
	return 0;
}