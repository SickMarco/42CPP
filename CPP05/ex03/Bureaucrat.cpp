/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:19 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 14:55:56 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const std::string& setName, const int setGrade) : _name(setName){
	if (setGrade < 1)
		throw  GradeTooHighException();
	else if (setGrade > 150)
		throw GradeTooLowException();
	this->_grade = setGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: _name(src._name), _grade(src._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src){
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

std::string Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

void Bureaucrat::promotion(){
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::demotion(){
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
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

void Bureaucrat::signForm(AForm& f) const{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< this->_name << " couldn’t sign " << f.getName()
					<< " because: "<< e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const& form){
	try
	{
		form.execute(*this);
		std::cout << this->_name << " execute " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< this->_name << " couldn’t execute " << form.getName()
					<< " because: "<< e.what() << '\n';
	}
}