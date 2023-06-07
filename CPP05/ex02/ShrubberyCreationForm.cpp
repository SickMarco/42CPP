/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:45:12 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 19:52:35 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 0, 0), _target(""){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm(src), _target(src._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
	if (!this->getSign())
		throw AForm::IsNotSigned();
	else if (executor.getGrade() > this->getExeGrade())
		throw AForm::GradeTooLowException();

	std::cout << executor.getName() << " is drawing ASCII trees inside " << this->getTarget().append("_shrubbery") << std::endl;
	std::ofstream file ((this->getTarget().append("_shrubbery").c_str()));
	file << "       /\\       " 	 << std::endl;
	file << "      /\\*\\      " 	 << std::endl;
	file << "     /\\O\\*\\     " 	 << std::endl;
	file << "    /*/\\/\\/\\    " 	 << std::endl;
	file << "   /\\O\\/\\*\\/\\   "  << std::endl;
	file << "  /\\*\\/\\*\\/\\/\\  " << std::endl;
	file << " /\\O\\/\\/*/\\/O/\\ "  << std::endl;
	file << "       ||       " 		 << std::endl;
	file << "       ||       " 		 << std::endl;
	file << "       ||       "	 	 << std::endl;
	file.close();
}
