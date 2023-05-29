/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:01:35 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/29 17:16:48 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "WrongCat Default constructor" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Default destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src){
	std::cout << "WrongCat Copy constructor" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat& src){
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << "ER SAMBUCONE MOLINARI" << std::endl;
}