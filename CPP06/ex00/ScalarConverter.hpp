/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:28 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/16 16:01:44 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cerrno>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <cfloat>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& src);

	static char _c;
	static int _i;
	static float _f;
	static double _d;
	static bool _error;
	static bool _inf;

public:
	static void convert(const std::string& src);
	static void typeFinder(const std::string& input);
	static void charConv(const std::string& src);
	static void intConv(const std::string& src);
	static void floatConv(const std::string& src);
	static void doubleConv(const std::string& src);
	static void convPrinter(const std::string& src);
};

#endif