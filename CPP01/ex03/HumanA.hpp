/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:03:36 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/21 20:03:36 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
	std::string name;
	Weapon &M4;
public:
	HumanA(std::string set_n, Weapon &set_w);
	~HumanA();
	void attack();
};