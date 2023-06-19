/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:49 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/19 16:47:24 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): capacity(0), container(0){}

Span::~Span(){}

Span::Span(const unsigned int N) : capacity(N){
	container.reserve(N);
}

Span::Span(const Span& src){
	*this = src;
}

Span& Span::operator=(const Span& src){
	if (this != &src)
	{
		this->capacity = src.capacity;
		this->container = src.container;
	}
	return *this;
}

void Span::addNumber(const int newNum){
	if (container.size() >= capacity)
		throw std::out_of_range("The container is full");
	container.push_back(newNum);
}

unsigned int Span::longestSpan() const{
	if (!container.size())
		throw std::runtime_error("Container is empty");
	else if (container.size() < 2)
		throw std::runtime_error("Found only one number in container");

	int max = *std::max_element(container.begin(), container.end());
	int min = *std::min_element(container.begin(), container.end());
	return max - min;
}

unsigned int Span::shortestSpan(){
	if (!container.size())
		throw std::runtime_error("Container is empty");
	else if (container.size() < 2)
		throw std::runtime_error("Found only one number in container");

	int span = INT_MAX;
	std::sort(container.begin(), container.end());
	for (std::vector<int>::const_iterator it = container.begin(); it != container.end() - 1; ++it){
		if ((*(it + 1) - *it) < span)
			span = *(it + 1) - *it;
	}
	return span;
}