/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:26 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/16 17:03:01 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::_c;
int ScalarConverter::_i;
float ScalarConverter::_f;
double ScalarConverter::_d;
bool ScalarConverter::_error;
bool ScalarConverter::_inf;

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

bool isInt(const std::string& input) {
    std::stringstream ss(input);
	int i;
    ss >> i;
    return ss.eof() && !ss.fail();
}

bool isFloat(const std::string& input) {
	std::string trim = input;
	trim.erase(trim.length() - 1);
    std::stringstream ss(trim);
	float f;
    ss >> f;
    return ss.eof() && !ss.fail();
}

bool isDouble(const std::string& input) {
    std::stringstream ss(input);
	double d;
    ss >> d;
    return ss.eof() && !ss.fail();
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

int precisionFinder(const std::string& input){
	
	size_t pos = 0;
	size_t trim = 1;
	if (input[input.length() - 1] == 'f')
		trim++;
	pos = input.find('.');
	if (pos != input.npos)
		return input.length() - pos - trim;
	return 1;
}

void ScalarConverter::ScalarConverter::convPrinter(const std::string& input){

	std::cout << "Char: ";
	if (isprint(_c) && !_inf && _i > std::numeric_limits<char>::min() && _i < std::numeric_limits<char>::max())
		std::cout << "'" << _c << "'" << std::endl;
	else if (!_error && !_inf && _i > std::numeric_limits<char>::min() && _i < std::numeric_limits<char>::max())
		std::cout << "Non displayable" << std::endl;
	else if (_error || _inf ||  _i < std::numeric_limits<char>::min() || _i > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;

	std::cout << "Int: ";
	if (!_error && !_inf && _i > std::numeric_limits<int>::min() && _i < std::numeric_limits<int>::max())
		std::cout << _i << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "Float: ";
	if (!_error && !_inf && _f > -FLT_MAX && _f < FLT_MAX)
		 std::cout << std::fixed << std::setprecision(precisionFinder(input)) << _f << "f" << std::endl;
	else if (_inf)
		std::cout << (input[0] == '-' ? "-" : "+") << "inff" << std::endl;
	else
		std::cout << "nanf" << std::endl;

	std::cout << "Double: ";
	if (!_error && !_inf && _d > -DBL_MAX && _d < DBL_MAX)
		 std::cout << std::fixed << std::setprecision(precisionFinder(input)) << _d << std::endl;
	else if (_inf)
		std::cout << (input[0] == '-' ? "-" : "+") << "inf" << std::endl;
	else
		std::cout << "nan" << std::endl;
}

void ScalarConverter::typeFinder(const std::string& input){
	
	
	if (input.find("nan") != input.npos)
		_error = true;
	else if (input.find("inf") != input.npos)
		_inf = true;
	if (input.length() == 1 && !isdigit(static_cast<unsigned char>(input[0])))
		charConv(input);
	else if (isInt(input))
		intConv(input);
	else if (input[input.length() - 1] == 'f' && isFloat(input))
		floatConv(input);
	else if (isDouble(input))
		doubleConv(input);
	else
		_error = true;
}

void ScalarConverter::convert(const std::string& input){

	_error = false;
	_inf = false;
	typeFinder(input);
	convPrinter(input);
}