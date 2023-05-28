/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:53:46 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/28 16:06:13 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap Default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string& setName): ClapTrap(setName){
	std::cout << "ScavTrap Parameterized constructor" << std::endl;
	this->_healt = 100;
	this->_energy = 100;
	this->_attackDamage = 30;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(){
	std::cout << "ScavTrap Copy constructor" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Default destructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src){
	if (this != &src)
	{
		this->_name = src._name;
		this->_healt = src._healt;
		this->_energy = src._energy;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}