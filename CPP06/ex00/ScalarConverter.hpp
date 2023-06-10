/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:28 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/10 16:24:31 by mbozzi           ###   ########.fr       */
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

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	static char _c;
	static int _i;
	static float _f;
	static double _d;
	static bool _error;

public:
	static void convert(const std::string& src);
	static void charConv(const std::string& src);
	static void intConv(const std::string& src);
	static void floatConv(const std::string& src);
	static void doubleConv(const std::string& src);
	static void convPrinter();
};




#endif