/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:06 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/23 15:00:35 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedNb(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& oldClass ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = oldClass;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixedNb = src.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedNb;
}

void Fixed::setRawBits( int const raw ){
	fixedNb = raw;
}