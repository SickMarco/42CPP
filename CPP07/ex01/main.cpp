/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:58:55 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/21 14:20:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <math.h>

void pow2(int& x){
	
	x *= x;
}

void eraser(char& c){

	c = '\0';
}


int main()
{
	int array[5] = {5, 1, 0, 4, 2};
	::iter(array, 5, pow2);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << std::endl;

	char str[17] = "This is an array";
	std::cout << "Array: " << str << std::endl;
	::iter(str, 17, eraser);
	std::cout  << "Erased array: " << str << std::endl;
}