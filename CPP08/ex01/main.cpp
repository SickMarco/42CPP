/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:32:58 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/23 15:48:05 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	int array[] = {-1, 6, 1, 17, 9, 11};
	Span sp(6);
	for (int i = 0; i < 5; i++)
		sp.addNumber(array[i]);
	std::cout << "addNumber:" << std::endl << sp.shortestSpan() << std::endl << sp.longestSpan() << std::endl;
	try { 
		sp.addNumber(42);
	}
	catch(const std::exception& e){ std::cerr << e.what() << std::endl; }

	std::vector<int> numbers(array, array + (sizeof(array) / sizeof(array[0])));
	Span sp2(6);
	sp2.addNumberIterator(numbers.begin(), numbers.end());
	std::cout << "addNumberIterator:" << std::endl << sp.shortestSpan() << std::endl << sp.longestSpan() << std::endl;
 	try	{
		int test[] = {42, 1997};
		std::vector<int> test_vector(test, test + (sizeof(test) / sizeof(test[0])));
		sp2.addNumberIterator(test_vector.begin(), test_vector.end());
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
	return 0;
}