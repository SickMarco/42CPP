/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:06 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/26 16:25:14 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

// CONSTRUCTOR
Fixed::Fixed() : _fixedNb(0) {
	std::cout << "Default constructor called" << std::endl;
}

// INT CONSTRUCTOR
Fixed::Fixed(const int initNb) : _fixedNb(initNb << _fractBits){
	std::cout << "Int constructor called" << std::endl;
}

// FLOAT CONSTRUCTOR
Fixed::Fixed(const float initNb) : _fixedNb(roundf(initNb * (1 << _fractBits))) {
	std::cout << "Float constructor called" << std::endl;
}

// COPY CONTRUCTOR
Fixed::Fixed(const Fixed& oldClass) {
	std::cout << "Copy constructor called" << std::endl;
	*this = oldClass;
}

// DESTRUCTOR
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// COPY ASSIGNMENT OPERATOR (= OVERLOAD)
Fixed& Fixed::operator = (const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedNb = src._fixedNb;
	return *this;
}

// << OVERLOAD
std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}

int Fixed::getRawBits(void) const{
	return _fixedNb;
}

void Fixed::setRawBits(int const raw){
	_fixedNb = raw;
}

float Fixed::toFloat(void) const{
	return (float)_fixedNb / (1 << _fractBits); 
}

int Fixed::toInt(void) const{
	return _fixedNb >> _fractBits;
}