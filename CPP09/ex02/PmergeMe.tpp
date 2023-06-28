/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:59:35 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/28 20:01:29 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void containerPrinter(const T& ctr){
	for (typename T::const_iterator it = ctr.begin(); it < ctr.end(); ++it){
		std::cout << *it << ((it + 1 == ctr.end()) ? "\n" : " ");
	}
}

template <typename T>
void insertionSort(T& ctr){
    unsigned int tmp;
    for (typename T::iterator it = ctr.begin(); it < ctr.end(); ++it) {
        tmp = *it;
        typename T::iterator j = it;
        while (j != ctr.begin() && *(j - 1) > tmp) {
            *j = *(j - 1);
            --j;
        }
        *j = tmp;
    }
}

/* template <typename T>
void mergeSort(T& ctr){
	
} */

template <typename T>
double alghoritmTime(T& ctr, clock_t start_time){
	insertionSort(ctr);
	clock_t end = clock();
	return static_cast<double>(end - start_time) / CLOCKS_PER_SEC;
}


