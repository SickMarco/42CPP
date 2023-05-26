/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:40:33 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/26 16:38:12 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

/*  Vertex (1, 2), (3, 4) e (5, 2). Inside point is (3, 3). Outside point is (0, 0).

	Vertex (0, 0), (4, 0) e (2, 3). Inside point is (2, 1). Outside point is (5, 5). 
	
	Vertex (0, 0), (6, 0) e (3, 4). Inside point is (3, 2). Outside point is (-1, 1). On border point is (4, 2).*/

int main( void ) 
{
	std::string list[4] = {"A", "B", "C", "P"};
	Point pts[4];
	float x, y;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Intert cordinate for point " << list[i] << " [X Y]: ";
		if (std::cin >> x >> y)
			pts[i] = Point(x, y);
		else
			return 1;
	}
	if (bsp(pts[0], pts[1], pts[2], pts[3]))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;
	return 0;
}