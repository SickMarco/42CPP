/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:05:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/20 20:14:35 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<class T> MutantStack<T>::MutantStack(){}

template<class T> MutantStack<T>::~MutantStack(){}

template<class T> MutantStack<T>::MutantStack(const MutantStack<T> &src){
	*this = src;
}

template<class T> MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &src){
	if (this != &src)
		this->c = src.c;
	return *this;
}

template<class T> typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<class T> typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

