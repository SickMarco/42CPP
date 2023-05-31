/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:01:25 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/31 18:08:58 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), br(new Brain()){
	std::cout << "Dog Default constructor" << std::endl;
	Animal::_type = "Doggo";
	this->_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Dog Default destructor" << std::endl;
	delete this->br;
}

Dog::Dog(const Dog& src) : Animal(src), br(new Brain(*src.br)){
	std::cout << "Dog Copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& src){
	if (this != &src)
    {
        Animal::operator=(src);
        delete br;
        br = new Brain(*src.br);
    }
    return *this;
}

void Dog::makeSound() const{
	std::cout << "BAU!" << std::endl;
}