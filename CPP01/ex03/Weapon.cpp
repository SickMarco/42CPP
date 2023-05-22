/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:03:50 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/22 14:16:45 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const{
	return type;
}

void Weapon::setType( std::string newType ){
	type = newType;
}
