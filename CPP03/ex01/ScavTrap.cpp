/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:53:46 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/27 17:03:39 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "Default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string& setName): ClapTrap(setName){
	std::cout << "Parameterized constructor" << std::endl;
	this->setTrap(setName, 100, 50, 20);
}

ScavTrap::ScavTrap(const ScavTrap& src){
	std::cout << "Copy constructor" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "Default destructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src){
	if (this != &src)
		this->setTrap(src.getName(), src.getHealt(), src.getEnergy(), src.getAttackDmg());
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}