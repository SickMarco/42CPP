/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:01:25 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/01 19:34:34 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Default constructor" << std::endl;
	A_Animal::_type = "Doggo";
	this->_type = "Dog";
	this->br = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog Default destructor" << std::endl;
	delete this->br;
}

Dog::Dog(const Dog& src) : A_Animal(src){
	std::cout << "Dog Copy constructor" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog& src){
	if (this != &src)
    {
        A_Animal::operator=(src);
        delete br;
        br = new Brain(*src.br);
    }
    return *this;
}

void Dog::makeSound() const{
	std::cout << "BAU!" << std::endl;
}