/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:02:23 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/25 16:17:28 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
	Fixed _x;
	Fixed _y;

public:
	Point();
	Point( const float nX, const float nY );
	Point( const Point& src );
	~Point();

	Point& operator=(const Point& src);
	Fixed gX( void ) const;
	Fixed gY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif