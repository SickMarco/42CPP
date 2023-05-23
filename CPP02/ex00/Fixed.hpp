/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:55:09 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/23 14:59:59 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixedNb;
		static const int rawBits = 8;
	
	public:
		Fixed();
		Fixed( const Fixed &oldClass );
		~Fixed();

		Fixed& operator=(const Fixed& src);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif