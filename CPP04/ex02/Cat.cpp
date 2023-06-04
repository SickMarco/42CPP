/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:39:43 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/04 12:28:07 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Default constructor" << std::endl;
	A_Animal::_type = "Kitty";
	this->_type = "Cat";
	this->br = new Brain();
}

Cat::~Cat(){
	std::cout << "Cat Default destructor" << std::endl;
	delete this->br;
}

Cat::Cat(const Cat& src) : A_Animal(src){
	std::cout << "Cat Copy constructor" << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat& src){
	if (this != &src)
	{
		A_Animal::operator=(src);
		this->br = new Brain(*src.br);
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "MEOW!" << std::endl;
}