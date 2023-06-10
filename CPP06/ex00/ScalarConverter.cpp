/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:26 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/10 16:30:12 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum Type {Char = 0, Int = 1, Float = 2, Double = 3, Nan = 4, Inf = 5};

char ScalarConverter::_c;
int ScalarConverter::_i;
float ScalarConverter::_f;
double ScalarConverter::_d;
bool ScalarConverter::_error;

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

int typeFinder(const std::string& src){
	
	if (src.length() == 1 && !isdigit(static_cast<unsigned char>(src[0])))
		return Char;
	else if (src.find("nan") != src.npos)
		return Nan;
	else if (src.find("inf") != src.npos)
		return Inf;
	size_t i;
	for (i = 0; i < src.length(); i++)
		if (!isdigit(src[i]) && src[i] != '-' && src[i] != '+')
			break;
	if (i == src.length())
		return Int;
	for (i = 0; i < src.length(); i++)
		if (!isdigit(src[i]) && src[i] != '-' && src[i] != '+' && src[i] != 'f' && src[i] != '.')
			break;
	if (i == src.length())
		return Float;
	for (i = 0; i < src.length(); i++)
		if (!isdigit(src[i]) && src[i] != '-' && src[i] != '+' && src[i] != '.')
			break;
	if (i == src.length())
		return Double;
	return Nan;
}

void ScalarConverter::charConv(const std::string& src){
	
	_c = src[0];
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_c);
	_d = static_cast<double>(_c);
}

void ScalarConverter::intConv(const std::string& src){
	
	_i = std::strtol(src.c_str(), 0, 10);
	if (errno == ERANGE){
		_error = true;
		return ;
	}
	_c = static_cast<char>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
}

void ScalarConverter::floatConv(const std::string& src){
	
	_f = std::strtof(src.c_str(), 0);
	if (errno == ERANGE){
		_error = true;
		return ;
	}
	_c = static_cast<char>(_f);
	_i = static_cast<int>(_f);
	_d = static_cast<double>(_f);
}

void  ScalarConverter::doubleConv(const std::string& src){
	
	_d = std::strtod(src.c_str(), 0);
	if (errno == ERANGE){
		_error = true;
		return ;
	}
	_c = static_cast<char>(_d);
	_i = static_cast<int>(_d);
	_f = static_cast<float>(_d);
}

void ScalarConverter::ScalarConverter::convPrinter(){
	
	std::cout << "Char: ";
	if (isprint(_c))
		std::cout << "'" << _c << "'" << std::endl;
	else if (!_error && _c > std::numeric_limits<char>::min() && _c < std::numeric_limits<char>::max())
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "Int: ";
	if (!_error && _i > std::numeric_limits<int>::min() && _i < std::numeric_limits<int>::max())
		std::cout << _i << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "Float: ";
	if (!_error && _f > std::numeric_limits<float>::min() && _f < std::numeric_limits<float>::max())
		std::cout << _f << "f" << std::endl;
	else
		std::cout << "nanf" << std::endl;

	std::cout << "Double: ";
	if (!_error && _d > std::numeric_limits<double>::min() && _d < std::numeric_limits<double>::max())
		std::cout << _d << std::endl;
	else
		std::cout << "nan" << std::endl;
}

void ScalarConverter::convert(const std::string& src){

	_error = false;
	int type = typeFinder(src);
	switch (type)
	{
	case Char:
		charConv(src);
		break;
	case Int:
		intConv(src);
		break;
	case Float:
		floatConv(src);
		break;
	case Double:
		doubleConv(src);
		break;
	case Nan:
		_error = true;
		break;
	default:
		break;
	}
	convPrinter();
}
	

		/* int i = std::strtol(src.c_str(), 0 , 10);
	if (errno != ERANGE && i > std::numeric_limits<int>::min() && i < std::numeric_limits<int>::max())
		return Int; */