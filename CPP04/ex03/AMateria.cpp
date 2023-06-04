/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:32:11 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/04 18:58:35 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type){
	this->_type = type;
}

AMateria::~AMateria(){}

std::string const & AMateria::getType() const{
	return this->_type;
}

void AMateria::use(ICharacter& target){
	(void)target;
}