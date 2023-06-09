/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:26 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/09 13:26:11 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string& src){

	std::cout << "char: ";
	try
	{
		int conv = std::stoi(src);
		if (conv > std::numeric_limits<char>::min() && conv < std::numeric_limits<char>::max())
			std::cout << "'" << static_cast<char>(conv) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible"  << std::endl;
	}

	std::cout << "int: ";
	try
	{
		int conv = std::stoi(src);
		std::cout << conv << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "float: ";
	try
	{
		float conv = std::stof(src);
		std::cout << conv << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "nanf" << std::endl;
	}
	
	std::cout << "double: ";
	try
	{
		float conv = std::stod(src);
		std::cout << conv << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "nan" << std::endl;
	}
}
	