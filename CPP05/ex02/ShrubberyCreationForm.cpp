/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:45:12 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 12:33:41 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 0, 0){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137){}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
	if (!this->getSign())
		throw AForm::IsNotSigned();
	else if (executor.getGrade() > this->getExeGrade())
		throw AForm::GradeTooLowException();

	std::cout << executor.getName() << " is drawing ASCII trees inside " << this->getName().append("_shrubbery") << std::endl;
	std::ofstream file (this->getName().append("_shrubbery"));
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
