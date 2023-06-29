/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:01:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/29 12:19:52 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <ctime>

#define DELIMITER 6
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[1;0m"

class PmergeMe
{
private:
	std::vector<unsigned int> vct;
	std::deque<unsigned int> dqe;
	clock_t start_time;
	PmergeMe();

public:
	PmergeMe(const std::string& numberList);
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	~PmergeMe();

	void containerInit(const std::string& numberList);
	void order();
};

#include "PmergeMe.tpp"

#endif