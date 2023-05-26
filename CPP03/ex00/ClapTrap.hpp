/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:45:32 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/26 12:20:44 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _healt;
	unsigned int _energy;
	unsigned int _attackDamage;

public:
	ClapTrap();
	ClapTrap(const std::string& setName);
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);	
};

#endif