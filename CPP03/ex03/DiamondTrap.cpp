/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:21:37 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/29 12:11:16 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap(){
	std::cout << "DiamondTrap Default constructor" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap Default destructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string& setName) : ClapTrap(setName), FragTrap(setName), ScavTrap(setName){
	std::cout << "DiamondTrap Parameterized constructor" << std::endl;
	this->_name = setName;
	ClapTrap::_name = setName.append("_clap_name");
	this->_healt = FragTrap::_healt;
	this->_energy = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(), FragTrap(), ScavTrap(){
	std::cout << "DiamondTrap Copy constructor" << std::endl;
	*this = src;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src){
	if (this != &src)
	{
		ClapTrap::_name = src._name + "_clap_name";
		this->_name = src._name;
		this->_healt = src._healt;
		this->_energy = src._energy;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

void DiamondTrap::whoAmI(){
	std::cout << "I'm " << ClapTrap::_name << " also known as " << DiamondTrap::_name << std::endl;
}