/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:36:15 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/26 16:26:01 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
private:
	std::string expression;
	std::stack<int> stk;
	RPN();
public:
	RPN(const std::string& exp);
	RPN(const RPN& src);
	RPN& operator=(const RPN& src);
	~RPN();

	void calculator();
};

#endif