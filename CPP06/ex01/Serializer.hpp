/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:06 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/12 18:40:34 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& src);
	Serializer& operator=(const Serializer& src);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	
};

#endif