/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:34:04 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/08 12:20:48 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

AForm* Intern::makeForm(const std::string& formType, const std::string& target){
	
	std::string option[3] = {"shrubbery",
							 "robotomy",
							 "pardon"};

	int i;
	for (i = 0; i < 3; i++)
		if (!option[i].compare(formType))
			break;
	switch (i)
	{
	case 0:
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return new ShrubberyCreationForm(target);
		break;
	case 1:
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return new RobotomyRequestForm(target);
		break;
	case 2:
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return new PresidentialPardonForm(target);
		break;
	default:
		std::cout << "Form type not found" << std::endl;
		break;
	}
	return NULL;
}