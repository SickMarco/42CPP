/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:01:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/28 20:02:28 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <deque>
#include <ctime>

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