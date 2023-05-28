/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:53:52 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/28 15:37:44 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
protected:
	ScavTrap();
public:
	ScavTrap(std::string& setName);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& src);

	void guardGate();
};

#endif