/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:09 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/26 16:17:58 by mbozzi           ###   ########.fr       */
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

	Fixed operator+( const Fixed& add) const;
	Fixed operator-( const Fixed& sub) const;
	Fixed operator*( const Fixed& mult ) const;
	Fixed operator/( const Fixed& mult ) const;

	Fixed& operator++( void );
	Fixed operator++( int );
	Fixed& operator--( void );
	Fixed operator--( int );

	bool operator>( const Fixed &cmp ) const;
	bool operator<( const Fixed &cmp ) const;
	bool operator>=( const Fixed &cmp ) const;
	bool operator<=( const Fixed &cmp ) const;
	bool operator==( const Fixed &cmp ) const;
	bool operator!=( const Fixed &cmp ) const;

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed& min( Fixed& x, Fixed& y );
	static const Fixed& min( const Fixed& x, const Fixed& y );
	static Fixed& max( Fixed& x, Fixed& y );
	static const Fixed& max( const Fixed& x, const Fixed& y );
};

std::ostream& operator<<( std::ostream& os, const Fixed& f );

#endif