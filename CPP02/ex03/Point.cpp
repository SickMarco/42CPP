/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:02:23 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/25 16:18:11 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point( const float nX, const float nY ) : _x(nX), _y(nY) {
}

Point::~Point(){
}

Point& Point::operator=(const Point& src){
	if (this != &src){
		this->_x = src._x;
		this->_y = src._y;
	}
	return *this;
}

Point::Point(const Point& src) : _x(src._x),  _y(src._y){
}

Fixed Point::gX( void ) const {
		return this->_x;
}

Fixed Point::gY( void ) const {
		return this->_y;
}