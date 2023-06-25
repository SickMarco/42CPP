/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:49 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/23 16:30:35 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): capacity(0), container(0){}

Span::~Span(){}

Span::Span(const unsigned int N) : capacity(N){
	container.reserve(N);
}

Span::Span(const Span& src) : capacity(src.capacity), container(src.container){}

Span& Span::operator=(const Span& src){
	if (this != &src) {
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
	else if (container.size() == 1)
		throw std::runtime_error("Found only one number in container");

	return *std::max_element(container.begin(), container.end()) - *std::min_element(container.begin(), container.end());
}

unsigned int Span::shortestSpan() const{
	if (!container.size())
		throw std::runtime_error("Container is empty");
	else if (container.size() == 1)
		throw std::runtime_error("Found only one number in container");

	unsigned int span = UINT_MAX;
	std::vector<int> sorted(container);
	std::sort(sorted.begin(), sorted.end());
	for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.end() - 1; ++it){
		if (static_cast<unsigned int>(*(it + 1) - *it) < (span))
			span = *(it + 1) - *it;
	}
	return span;
}

void Span::addNumberIterator(const std::vector<int>::iterator& first, const std::vector<int>::iterator& last){
	if (container.size() + std::distance(first, last) > capacity)
		throw std::out_of_range("Not enough space in container");
	container.insert(container.end(), first, last);
}