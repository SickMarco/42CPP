/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:43:09 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/14 18:07:39 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <class T>
class Array
{
private:
	T* _arr;
	int _size;

public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const Array& src);
	Array& operator=(const Array& src);

	T& operator[](int i);
	int size() const;
};

#include "Array.tpp"

#endif