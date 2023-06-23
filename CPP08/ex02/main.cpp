/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:04:32 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/23 15:34:54 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "--- MUTANTSTACK ---" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	MutantStack<int> copy(mstack);
	MutantStack<int>::const_reverse_iterator it2 = copy.crbegin();
	MutantStack<int>::const_reverse_iterator ite2 = copy.crend();
	std::cout << "--- CONST_REVERSE MUTANTSTACK COPY ---" << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::vector<int> vct;
	vct.insert(vct.begin(), mstack.begin(), mstack.end());
	std::cout << "--- VECTOR ---" << std::endl;
	for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
		std::cout << *it << std::endl;
	return 0;
}