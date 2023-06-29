/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:59:35 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/29 12:21:04 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void containerPrinter(const T& ctr){
	for (typename T::const_iterator it = ctr.begin(); it < ctr.end(); ++it){
		std::cout << *it << ((it + 1 == ctr.end()) ? "\n" : " ");
	}
}

template <typename IT>
void insertionSort(IT begin, IT end){
    unsigned int tmp;
    for (IT it = begin; it < end; ++it){
        tmp = *it;
        IT j = it;
        while (j != begin && *(j - 1) > tmp){
            *j = *(j - 1);
            --j;
        }
        *j = tmp;
    }
}

template <typename T, typename IT>
void mergeInsertionSort(T& ctr, IT begin, IT end){
    if (begin < end - 1){
        IT mid = begin + std::distance(begin, end) / 2;
        if (std::distance(begin, mid) > DELIMITER)
            mergeInsertionSort(ctr, begin, mid);
        else
            insertionSort(begin, mid);
        if (std::distance(mid, end) > DELIMITER)
            mergeInsertionSort(ctr, mid, end);
        else
            insertionSort(mid, end);
        T tmp;
        std::merge(begin, mid, mid, end, std::back_inserter(tmp));
        std::copy(tmp.begin(), tmp.end(), begin);
    }
}

template <typename T>
double alghoritmTime(T& ctr, clock_t start_time){
    mergeInsertionSort(ctr, ctr.begin(), ctr.end());
	clock_t end = clock();
	return static_cast<double>(end - start_time) / CLOCKS_PER_SEC;
}