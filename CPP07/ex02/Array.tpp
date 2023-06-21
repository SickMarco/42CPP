/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:47:13 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/21 17:18:59 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<class T> Array<T>::Array() : _arr(new T[0]), _size(0){}

template<class T> Array<T>::~Array(){ delete[] _arr; }

template<class T> Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n){}

template<class T> Array<T>::Array(const Array<T> &src) : _arr(new T[src._size]), _size(src._size){
	for (int i = 0; i < src._size; i++){
			this->_arr[i] = src._arr[i];
	}
}

template<class T> Array<T>& Array<T>::operator=(const Array<T> &src){
	if (this != &src){
		delete[] this->_arr;
		this->_arr = new T[src._size];
		for (int i = 0; i < src._size; i++){
			this->_arr[i] = src._arr[i];
		}
		this->_size = src._size;
	}
	return *this;
}

template<class T> T& Array<T>::operator[](int i) const{
	if (i < 0)
		throw std::out_of_range("Negative index");
	else if (i >= this->_size)
		throw std::out_of_range("Index out of range");
	return this->_arr[i];
}

template<class T> int Array<T>::size() const { return this->_size; }

