/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:21:03 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/08 11:13:27 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 0, 0), _target(""){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const{
	if (!this->getSign())
		throw AForm::IsNotSigned();
	else if (executor.getGrade() > this->getExeGrade())
		throw AForm::GradeTooLowException();

	int random;
	srand(time(NULL));
	random = rand() % 2;
	switch (random)
	{
		case 0 :
			std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
			break;
		case 1 :
			std::cout << this->_target << " robotomy failed" << std::endl;
			break;
	}
}
	
	