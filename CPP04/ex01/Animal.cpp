/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:35:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/29 16:06:09 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal Default constructor" << std::endl;
	this->_type = "";
}

Animal::~Animal(){
	std::cout << "Animal Default destructor" << std::endl;
}

Animal::Animal(const Animal& src){
	std::cout << "Animal Copy destructor" << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal& src){
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const{
	std::cout << "..." << std::endl;
}