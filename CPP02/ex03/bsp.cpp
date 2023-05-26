/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:02:13 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/26 12:21:18 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Let A=(xA,yA), B=(xB,yB), and C=(xC,yC) be the three vertices of the triangle.

Let P=(xP,yP) be the point that we want to verify if it is inside the triangle.

Calculation:

D1=(xP−xA)(yC−yA)−(yP−yA)(xC−xA)

D2=(xA−xP)(yB−yA)−(yA−yP)(xB−xA)

D=(xB−xA)(yC−yA)−(yB−yA)(xC−xA)

a= D1 \ D; b= D2 \ D

If a>0 and b>0 and a+b<1 then P is inside the triangle. Otherwise, it is outside (or on the edge). */

bool bsp( Point const a, Point const b, Point const c, Point const point){
	
	Fixed d1, d2, d, z, v;

	d1 = (point.gX() - a.gX()) * (c.gY() - a.gY()) - ((point.gY() - a.gY()) * (c.gX() - a.gX()));
	d2 = ((a.gX() - point.gX()) * (b.gY() - a.gY()) - ((a.gY() - point.gY()) * (b.gX() - a.gX())));

	d = (((b.gX() - a.gX()) * (c.gY() - a.gY())) - ((b.gY() - a.gY()) * (c.gX() - a.gX())));

	z = d1 / d;
	v = d2 / d;
	
	return (z.toFloat() > 0) && (v.toFloat() > 0) && ((z.toFloat() + v.toFloat()) < 0.9);
}