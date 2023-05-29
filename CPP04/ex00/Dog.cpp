/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:01:25 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/29 15:46:41 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Dog Default constructor" << std::endl;
	Animal::_type = "Doggo";
	this->_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Doggo Default destructor" << std::endl;
}

Dog::Dog(const Dog& src){
	*this = src;
}

Dog& Dog::operator=(const Dog& src){
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "BAU!" << std::endl;
}