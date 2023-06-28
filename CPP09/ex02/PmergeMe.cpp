/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:01:26 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/28 20:02:24 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src) : vct(src.vct), dqe(src.dqe), start_time(src.start_time){}

PmergeMe& PmergeMe::operator=(const PmergeMe& src){
	if (this != &src){
		this->vct = src.vct;
		this->dqe = src.dqe;
		this->start_time = src.start_time;
	}
	return *this;
}

bool isValidList(const std::string& numberList){
	const std::string validArgs = "0123456789 ";
	for (size_t i = 0; i < numberList.length(); i++){
		if (validArgs.find(numberList[i]) == numberList.npos)
			return false;
	}
	return true;
}

void PmergeMe::containerInit(const std::string& numberList){
	std::istringstream iss(numberList);
	unsigned int num;
	start_time = clock();
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

void timePrinter(size_t size, double time, char Flag){
	std::cout 	<< "Time to process a range of " << size << " elements with std::"
				<< ((Flag == 'V') ? "vector" : "deque") << " : "
				<< std::fixed << time << " us" << std::endl;
}

void PmergeMe::order(){
	double vecTime, deqTime;
	std::cout << "Before:  ";
	containerPrinter(vct);
	vecTime = alghoritmTime(vct, start_time);
	deqTime = alghoritmTime(dqe, start_time);
	std::cout << "After:  ";
	containerPrinter(vct);
	timePrinter(vct.size(), vecTime, 'V');
	timePrinter(dqe.size(), deqTime - vecTime, 'D');
}