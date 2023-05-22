/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:03:39 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/22 14:08:21 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string new_n ) : name(new_n), AK47(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon( Weapon &set_w){
	AK47 = &set_w;
}
void HumanB::attack(){
	std::cout << name << " attacks with their " << AK47->getType() << std::endl;
}