/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:34:07 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/01 19:36:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
/* 	std::cout << "ANIMALS ALLOC\n" << std::endl;
	A_Animal* anm[100];
	for (int i = 0; i < 100; i++)
	{
		(i < 50) ? anm[i] = new(std::nothrow) Dog() : anm[i] = new(std::nothrow) Cat();
		if (!anm[i])
			return 1;
	}
	std::cout << "\nANIMALS DEALLOC\n" << std::endl;
	for (int i = 0; i < 100; i++)
		delete anm[i]; */

	A_Animal* anm1 = new Dog();
	A_Animal* anm2 = anm1;
	std::cout << anm1->getType() << std::endl;
	std::cout << anm2->getType() << std::endl;

	anm2->setType("KTM");

	std::cout << anm1->getType() << std::endl;
	std::cout << anm2->getType() << std::endl;
	

	delete anm1;
	//delete anm2;

/* 	A_Animal* anm3 = new Dog();
	A_Animal* anm4 = new Dog();

	anm3 = anm4;
	std::cout << anm3 << std::endl << anm4 << std::endl;
	delete anm1;
	delete anm2;
	//delete anm3;
	//delete anm4; */
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