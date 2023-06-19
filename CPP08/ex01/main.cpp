/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:32:58 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/19 19:19:23 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "addNumber:" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	int array[] = {6, 3, 17, 9, 11};
	std::vector<int> numbers(array, array + (sizeof(array) / sizeof(array[0])));
	Span sp2 = Span(5);
	sp2.addNumberIterator(numbers.begin(), numbers.end());
	std::cout << "addNumberIterator:" << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
 	try
	{
		int test[] = {42, 1997};
		std::vector<int> test_vector(test, test + (sizeof(test) / sizeof(test[0])));
		sp2.addNumberIterator(test_vector.begin(), test_vector.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}