/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:09 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/26 16:16:28 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedNb;
	static const int _fractBits;

public:
	Fixed();
	Fixed( const int initNb );
	Fixed( const float initNb );
	Fixed( const Fixed &oldClass );
	Fixed& operator=( const Fixed& src );
	~Fixed();


	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif