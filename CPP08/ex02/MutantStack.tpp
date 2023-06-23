/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:05:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/23 15:29:38 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>

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

template<class T> typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const{
	return this->c.begin();
}

template<class T> typename MutantStack<T>::const_iterator MutantStack<T>::cend() const{
	return this->c.end();
}

template<class T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){
	return this->c.rbegin();
}

template<class T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){
	return this->c.rend();
}

template<class T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const {
	return this->c.rbegin();
}

template<class T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const {
	return this->c.rend();
}


