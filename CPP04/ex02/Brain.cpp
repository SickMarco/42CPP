/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:14:13 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/01 18:33:36 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Default constructor" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain Default destructor" << std::endl;
}

Brain::Brain(const Brain& src){
	std::cout << "Brain Copy constructor" << std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain& src){
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i].clear();
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}