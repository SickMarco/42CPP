/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:34:07 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/04 12:36:42 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog* anm1 = new Dog();
	Dog* anm2 = new Dog(*anm1);
	std::cout << anm1->getType() << std::endl;
	std::cout << anm2->getType() << std::endl;

	anm1->setType("German Shepherd");
	anm2->setType("Pitbull");

	std::cout << anm1->getType() << std::endl;
	std::cout << anm2->getType() << std::endl;

	delete anm1;
	delete anm2;

	Cat cat1;
	Cat cat2(cat1);

	cat1.setType("Sphynx");

	std::cout << cat1.getType() << std::endl;
	std::cout << cat2.getType() << std::endl;

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