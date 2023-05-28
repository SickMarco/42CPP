/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:20:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/28 16:06:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap Default constructor" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Default destructor" << std::endl;
}

FragTrap::FragTrap(std::string& setName): ClapTrap(setName){
	std::cout << "FragTrap Parametized constructor" << std::endl;
	this->_healt = 100;
	this->_energy = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(){
	std::cout << "FragTrap Copy constructor" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src){
	if (this != &src)
	{
		this->_name = src._name;
		this->_healt = src._healt;
		this->_energy = src._energy;
		this->_attackDamage= src._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->_name << " request positive high fives" << std::endl;
}