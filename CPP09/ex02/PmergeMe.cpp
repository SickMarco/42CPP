/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:01:26 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/27 15:38:11 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isValidList(const std::string& numberList){
	const std::string validArgs = "0123456789 ";
	for (size_t i = 0; i < numberList.length(); i++){
		if (validArgs.find(numberList[i]) == numberList.npos)
			return false;
	}
	return true;
}

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

void PmergeMe::containerInit(const std::string& numberList){
	std::istringstream iss(numberList);
	unsigned int num;
	while (iss >> num){
		vct.push_back(num);
		dqe.push_back(num);
	}
}

PmergeMe::PmergeMe(const std::string& numberList){
	if (!isValidList(numberList))
		throw std::runtime_error("Not valid number list");
	containerInit(numberList);
}

template <typename T>
void containerPrinter(const T& ctr){
	for (typename T::const_iterator it = ctr.begin(); it < ctr.end(); ++it){
		std::cout << *it << ((it + 1 == ctr.end()) ? "\n" : " ");
	}
}

void PmergeMe::order(){
	containerPrinter(vct);
	containerPrinter(dqe);
}