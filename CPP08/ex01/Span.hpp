/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:51 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/19 18:46:41 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

class Span
{
private:
	unsigned int capacity;
	std::vector<int> container;
	Span();

public:
	~Span();
	Span(const unsigned int N);
	Span(const Span& src);
	Span& operator=(const Span& src);
	void addNumber(const int newNum);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	void addNumberIterator(const std::vector<int>::iterator& it1, const std::vector<int>::iterator& it2);
};

#endif