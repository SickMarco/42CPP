/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:01:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/27 15:37:58 by mbozzi           ###   ########.fr       */
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

class PmergeMe
{
private:
	std::vector<unsigned int> vct;
	std::deque<unsigned int> dqe;
	PmergeMe();

public:
	PmergeMe(const std::string& numberList);
	~PmergeMe();

	void containerInit(const std::string& numberList);
	void order();
};

#endif