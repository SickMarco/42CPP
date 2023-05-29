/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:02:10 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/29 17:20:32 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal Default constructor" << std::endl;
	this->_type = "";
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Default destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src){
	std::cout << "WrongAnimal Copy constructor" << std::endl;
	*this = src;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src){
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void WrongAnimal::makeSound() const{
	std::cout << "..." << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->_type;
}