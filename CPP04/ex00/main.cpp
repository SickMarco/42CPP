/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:34:07 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/29 17:29:15 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	//...
	delete meta;
	delete j;
	delete i;

	const WrongAnimal* metaW = new WrongAnimal();
	const WrongAnimal* iW = new WrongCat();
	std::cout << iW->getType() << " " << std::endl;
	iW->makeSound(); //will output the cat sound!
	metaW->makeSound();
	delete metaW;
	delete iW;
	return 0;
}