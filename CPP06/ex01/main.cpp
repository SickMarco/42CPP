/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:40:28 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/12 18:53:57 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *data = new Data();
	data->test = 42;

	std::cout << data << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	Data* serializedData = Serializer::deserialize(raw);
	std::cout << serializedData << std::endl;

	std::cout << serializedData->test << std::endl;

	delete data;
}