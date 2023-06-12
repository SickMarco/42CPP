/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:40:58 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/12 18:42:46 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer& src){
	*this = src;
}

Serializer& Serializer::operator=(const Serializer& src){
	(void)src;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
	
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){

	return reinterpret_cast<Data*>(raw);
}