/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:03:29 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 12:07:44 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _signed(false), _signGrade(0), _exeGrade(0){
}

AForm::~AForm(){
}

AForm::AForm(const std::string& setName, const int setSign, const int setExe) 
	: _name(setName), _signed(false), _signGrade(setSign), _exeGrade(setExe) {

		if (_signGrade < 1 || _exeGrade < 1)
			throw AForm::GradeTooHighException();
		else if (_signGrade > 150 || _exeGrade > 150)
			throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) 
	: _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _exeGrade(src._exeGrade) {
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSign() const {
	return this->_signed;
}

int AForm::getSignGrade() const {
	return this->_signGrade;
}

int AForm::getExeGrade() const {
	return this->_exeGrade;
}

void AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f){
	os	<< "AForm " << f.getName() << (f.getSign() ? " is signed." : " is not signed.") 
		<< " AForm Requirements: Min. Sign Grade: " << f.getSignGrade()
		<< " and Min. Execution Grade: " << f.getSignGrade() << std::endl;
	return os;
}

const char* AForm::IsNotSigned::what() const throw(){
	return "The Form is not signed";
}