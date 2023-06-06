/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:19 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/06 16:01:44 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const std::string& setName, const int setGrade){
	if (setGrade < 1)
		throw  GradeTooHighException();
	else if (setGrade > 150)
		throw GradeTooLowException();
	this->_name = setName;
	this->_grade = setGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src){
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src){
	if (this != &src)
	{
		this->_name = src._name;
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
	else
		throw GradeTooHighException();
}

void Bureaucrat::minusGrade(){
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Error: Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
	return "Error: Grade too low";
};