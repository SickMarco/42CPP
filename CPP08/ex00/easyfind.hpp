/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:43:59 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/19 14:32:30 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template<typename T, typename U>
bool easyfind(const T& src, U x){
    for (typename T::const_iterator it = src.begin(); it != src.end(); ++it){
        if (*it == x)
            return true;
    }
    return false;
}

#endif