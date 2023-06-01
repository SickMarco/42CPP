/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:35:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/29 16:06:09 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

A_Animal::A_Animal(){
	std::cout << "A_Animal Default constructor" << std::endl;
	this->_type = "";
}

A_Animal::~A_Animal(){
	std::cout << "A_Animal Default destructor" << std::endl;
}

A_Animal::A_Animal(const A_Animal& src){
	std::cout << "A_Animal Copy constructor" << std::endl;
	*this = src;
}

A_Animal& A_Animal::operator=(const A_Animal& src){
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string A_Animal::getType() const {
	return this->_type;
}

void A_Animal::setType(const std::string& newType){
	this->_type = newType;
}

void A_Animal::makeSound() const{
	std::cout << "..." << std::endl;
}