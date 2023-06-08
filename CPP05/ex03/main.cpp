/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:01 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/08 18:02:47 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::string name;
	std::string formName;
	int grade;
	std::string formType;
	std::string target;
	AForm *form = NULL;

	while (!std::cin.eof())
	{
		std::cout << "Insert Bureaucrat Name: ";
		std::getline(std::cin, name);
		if (name.empty())
			continue;
		std::cout << "Insert Bureaucrat Grade: ";
		std::cin >> grade;
		std::cin.ignore(1000, '\n');
		std::cout << "Chose Form type [shrubbery, robotomy, pardon]: ";
		std::getline(std::cin, formType);
		std::cout << "Chose Form target: ";
		std::getline(std::cin, target);
		if (std::cin.eof())
			break;
		try {
			Bureaucrat b(name, grade);
			std::cout << "Name: " << b.getName() << " Grade: " << b.getGrade() << std::endl;
			Intern slave;
			form = slave.makeForm(formType, target);
			if (form)
			{
				form->beSigned(b);
				b.executeForm(*form);
			}
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		if (form)
			delete form;
	}
	return 0;
}