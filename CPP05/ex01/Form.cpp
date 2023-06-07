/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:03:29 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 15:47:00 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _signGrade(0), _exeGrade(0){
}

Form::~Form(){
}

Form::Form(const std::string& setName, const int setSign, const int setExe) 
	: _name(setName), _signed(false), _signGrade(setSign), _exeGrade(setExe) {

		if (_signGrade < 1 || _exeGrade < 1)
			throw Form::GradeTooHighException();
		else if (_signGrade > 150 || _exeGrade > 150)
			throw Form::GradeTooLowException();
}

Form::Form(const Form& src) 
	: _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _exeGrade(src._exeGrade) {
}

Form& Form::operator=(const Form& src){
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSign() const {
	return this->_signed;
}

int Form::getSignGrade() const {
	return this->_signGrade;
}

int Form::getExeGrade() const {
	return this->_exeGrade;
}

void Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f){
	os	<< "Form " << f.getName() << (f.getSign() ? " is signed." : " is not signed.") 
		<< " Form Requirements: Min. Sign Grade: " << f.getSignGrade()
		<< " and Min. Execution Grade: " << f.getSignGrade() << std::endl;
	return os;
}