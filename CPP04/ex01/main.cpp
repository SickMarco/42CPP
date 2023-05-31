/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:34:07 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/31 16:58:38 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "ANIMALS ALLOC\n" << std::endl;
	Animal* anm[100];
	for (int i = 0; i < 100; i++)
	{
		(i < 50) ? anm[i] = new(std::nothrow) Dog() : anm[i] = new(std::nothrow) Cat();
		if (!anm[i])
			return 1;
	}
	std::cout << "\nANIMALS DEALLOC\n" << std::endl;
	for (int i = 0; i < 100; i++)
		delete anm[i];
	return 0;
}

/* int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return 0;
} */