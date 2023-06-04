/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:03:32 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/04 19:14:17 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		delete this->materias[i];
}

Character::Character(const std::string& setName){
	this->_name = setName;
}

Character::Character(const Character& src){
	*this = src;
}

Character& Character::operator=(const Character& src){
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
			this->materias[i] = src.materias[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] == NULL)
			this->materias[i] = m;
	}
}

void Character::unequip(int idx){
	delete this->materias[idx];
	this->materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (this->materias[idx])
		this->materias[idx]->use(target);
}