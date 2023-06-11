/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:26 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/11 17:17:47 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& src){
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src){
	if (this != &src)
	{
		_c = src._c;
		_i = src._i;
		_f = src._f;
		_d = src._d;
		_error = src._error;
		_inf = src._inf;
	}
	return *this;
}

enum Type {Char = 0, Int = 1, Float = 2, Double = 3, Nan = 4, Inf = 5};

char ScalarConverter::_c;
int ScalarConverter::_i;
float ScalarConverter::_f;
double ScalarConverter::_d;
bool ScalarConverter::_error;
bool ScalarConverter::_inf;

bool isInt(const std::string& input) {
    std::istringstream iss(input);
    int i;
    iss >> std::noskipws >> i;
    return iss.eof() && !iss.fail();
}

bool isFloat(const std::string& input) {
	std::string trim = input;
	trim.erase(trim.length() - 1);
    std::istringstream iss(trim);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

bool isDouble(const std::string& input) {
    std::istringstream iss(input);
    double d;
    iss >> std::noskipws >> d;
    return iss.eof() && !iss.fail();
}

int typeFinder(const std::string& input){
	
	if (input.length() == 1 && !isdigit(static_cast<unsigned char>(input[0])))
		return Char;
	else if (input.find("nan") != input.npos)
		return Nan;
	else if (input.find("inf") != input.npos)
		return Inf;
	else if (isInt(input))
		return Int;
	else if (input[input.length() - 1] == 'f' && isFloat(input))
		return Float;
	else if (isDouble(input))
		return Double;
	return Nan;
}

void ScalarConverter::charConv(const std::string& input){
	
	_c = static_cast<char>(input[0]);
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_c);
	_d = static_cast<double>(_c);
}

void ScalarConverter::intConv(const std::string& input){
	
	_i = std::strtol(input.c_str(), 0, 10);
	if (errno == ERANGE){
		_error = true;
		return ;
	}
	_c = static_cast<char>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
}

void ScalarConverter::floatConv(const std::string& input){
	
	_f = std::strtof(input.c_str(), 0);
	if (errno == ERANGE){
		_error = true;
		return ;
	}
	_c = static_cast<char>(_f);
	_i = static_cast<int>(_f);
	_d = static_cast<double>(_f);
}

void  ScalarConverter::doubleConv(const std::string& input){
	
	_d = std::strtod(input.c_str(), 0);
	if (errno == ERANGE){
		_error = true;
		return ;
	}
	_c = static_cast<char>(_d);
	_i = static_cast<int>(_d);
	_f = static_cast<float>(_d);
}

void ScalarConverter::ScalarConverter::convPrinter(const std::string& input){
	
	std::cout << "Char: ";
	if (isprint(_c))
		std::cout << "'" << _c << "'" << std::endl;
	else if (!_error && !_inf && _c > std::numeric_limits<char>::min() && _c < std::numeric_limits<char>::max())
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "Int: ";
	if (!_error && !_inf && _i > std::numeric_limits<int>::min() && _i < std::numeric_limits<int>::max())
		std::cout << _i << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "Float: ";
	if (!_error && !_inf && _f > -FLT_MAX && _f < FLT_MAX)
		std::cout << _f << "f" << std::endl;
	else if (_inf)
		std::cout << (input[0] == '-' ? "-" : "+") << "inff" << std::endl;
	else
		std::cout << "nanf" << std::endl;

	std::cout << "Double: ";
	if (!_error && !_inf && _d > -DBL_MAX && _d < DBL_MAX)
		std::cout << _d << std::endl;
	else if (_inf)
		std::cout << (input[0] == '-' ? "-" : "+") << "inf" << std::endl;
	else
		std::cout << "nan" << std::endl;
}

void ScalarConverter::convert(const std::string& input){

	_error = false;
	_inf = false;
	int type = typeFinder(input);
	switch (type)
	{
	case Char:
		charConv(input);
		break;
	case Int:
		intConv(input);
		break;
	case Float:
		floatConv(input);
		break;
	case Double:
		doubleConv(input);
		break;
	case Nan:
		_error = true;
		break;
	case Inf:
		_inf = true;
		break;
	default:
		std::cout << "Error finding type" << std::endl;
		return;
	}
	convPrinter(input);
}