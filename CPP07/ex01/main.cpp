/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:58:55 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/21 17:16:24 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <vector>

void pow2(int& x){	
	x *= x;
}

void eraser(char& c){
	c = '\0';
}

int main()
{
	std::cout << "--- ARRAY ---" << std::endl;
	int array[5] = {5, 1, 0, 4, 2};
	::iter(array, 5, pow2);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << std::endl;

	std::cout << "--- VECTOR ---" << std::endl;
	std::vector<int> test(array, array + sizeof(array) / sizeof(array[0]));
	::iter(test.data(), test.size(), pow2);
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it){
		std::cout << *it << std::endl;
	}

	std::string str = "This is an string";
	std::cout  << std::endl << "Array: " << str << std::endl;
	::iter(&str[0], str.size(), eraser);
	std::cout  << "Erased string: " << str << std::endl;
}