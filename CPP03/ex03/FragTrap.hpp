/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:19:19 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/28 15:28:41 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap
{
protected:
	FragTrap();
public:
	FragTrap(std::string& setName);
	FragTrap(const FragTrap& src);
	FragTrap& operator=(const FragTrap& src);
	~FragTrap();

	void highFivesGuys(void);
};

#endif