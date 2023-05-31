/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:39:43 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/31 14:58:08 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Default constructor" << std::endl;
	Animal::_type = "Kitty";
	this->_type = "Cat";
	this->br = new Brain();
}

Cat::~Cat(){
	std::cout << "Cat Default destructor" << std::endl;
	delete this->br;
}

Cat::Cat(const Cat& src){
	std::cout << "Cat Copy destructor" << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat& src){
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void Cat::makeSound() const{
	std::cout << "MEOW!" << std::endl;
}