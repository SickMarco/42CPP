/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:04:07 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/22 14:06:38 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie(){
	std::cout << "\e[0;90mZombie " << name << " died (what?)" << std::endl;
}

void Zombie::announce( void ){
	std::cout << "\e[0;32m" << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name( std::string zName ){
	name = zName;
}