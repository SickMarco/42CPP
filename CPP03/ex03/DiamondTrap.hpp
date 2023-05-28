/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:21:34 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/28 15:43:53 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
protected:
	std::string _name;
	DiamondTrap();
public:
	DiamondTrap(std::string& setName);
	DiamondTrap(const DiamondTrap& src);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& src);

	using ScavTrap::attack;
	void whoAmI();
};

#endif