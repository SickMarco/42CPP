/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:04:31 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/21 20:04:31 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string set_name) { name = set_name; }

Zombie::~Zombie() { std::cout << "\e[0;90mZombie " << name << " died (what?)" << std::endl; }

void Zombie::announce( void ) { std::cout << "\e[0;32m" << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }