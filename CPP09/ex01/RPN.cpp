/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:36:07 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/26 17:32:15 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isValidExp(const std::string& exp){
	const std::string validChar = "0123456789+-*/ ";
	for (size_t i = 0; i < exp.length(); i++){
		if (validChar.find(exp[i]) == exp.npos)
			return false;
	}
	return true;
}

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const std::string& exp){
	if (!isValidExp(exp))
		throw std::runtime_error("Error");
	expression = exp;
}

RPN::RPN(const RPN& src) : expression(src.expression), stk(src.stk){}

RPN& RPN::operator=(const RPN& src){
	if (this != &src){
		this->expression = src.expression;
		this->stk = src.stk;
	}
	return *this;
}

int add(const int& x, const int& y){ return x + y; }
int sub(const int& x, const int& y){ return x - y; }
int mult(const int& x, const int& y){ return x * y; }
int divs(const int& x, const int& y){ return x / y; }

void RPN::calculator(){
	const std::string ops = "+-*/";
	int (*fun[])(const int& x, const int& y) = {&add, &sub, &mult, &divs};

	for (size_t i = 0; i < expression.length(); i++){
		if (ops.find(expression[i]) != ops.npos){
			int secondNumber = stk.top();
			stk.pop();
			int result = fun[ops.find(expression[i])](stk.top(), secondNumber);
			stk.pop();
			stk.push(result);
		}
		else if (expression[i] != ' ')
			stk.push(expression[i] - '0');
	}
	std::cout << stk.top() << std::endl;
}

