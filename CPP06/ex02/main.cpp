/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:00:05 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/13 17:18:17 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>


void identify(Base* p){

	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
}

void identify(Base& p){

	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch(const std::exception&){}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	} catch(const std::exception&){}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	} catch(const std::exception&){}
}

Base* generate(){
	
	srand(time(NULL));
	int random = rand() % 3;
	switch (random)
	{
	case 0 :
		return new A();
	case 1 :
		return new B();
	case 2 :
		return new C();
	default:
		break;
	}
	return NULL;
}

int main()
{
	Base* rand = generate();
	identify(rand);
	identify(*rand);
	delete rand;
}