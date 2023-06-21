/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:00:57 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/21 14:31:52 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b){
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(T& a, T& b){ return (a < b) ? a : b; }

template<typename T>
T max(T& a, T& b){ return (a > b) ? a : b; }

#endif