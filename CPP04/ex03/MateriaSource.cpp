/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:05:27 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/04 18:13:51 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){}

MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria* mat) {
	this->materia = mat->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type){
	if (!type.compare("ice"))
		return new Ice();
	else if (!type.compare("cure"))
		return new Cure();
	else
		return 0;
}

