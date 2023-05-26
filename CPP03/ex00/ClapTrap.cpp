/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:26 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/26 12:54:02 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "Default constructor" << std::endl;
}

ClapTrap::~ClapTrap(){
}

ClapTrap::ClapTrap(const std::string& setName): _name(setName), _healt(10), _energy(10), _attackDamage(0){
	std::cout << "Parameterized constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	std::cout << "Copy constructor" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other)
	{
		this->_name = other._name;
		this->_healt = other._healt;
		this->_energy = other._energy;
		this->_attackDamage = other._attackDamage;
	}
	return(*this);
}

void ClapTrap::attack(const std::string& target){
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " ,causing " << this->_attackDamage << " of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " lose " << amount << " healt points during battle" << std::endl;
	_healt -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " repairs itself and gets " << amount << " healt points back" << std::endl;
	_healt += amount;
}
