/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:19 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/05 19:42:36 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const Bureaucrat& src, const int setGrade) : _name(src._name){
	//try-catch
}

Bureaucrat::Bureaucrat(const Bureaucrat& src){
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src){
	if (this != &src)
	{
		//this->_name = src._name;
		this->_grade = src._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

void Bureaucrat::plusGrade(){
	if (this->_grade > 1)
		this->_grade--;
}

void Bureaucrat::minusGrade(){
	if (this->_grade < 150)
		this->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ",  bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}