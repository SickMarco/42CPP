/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:01 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/08 11:28:59 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::string name;
	std::string formName;
	int grade;
	int formType;
	std::string target;
	AForm *form;

	while (!std::cin.eof())
	{
		std::cout << "Insert Bureaucrat Name: ";
		std::getline(std::cin, name);
		if (name.empty())
			continue;
		std::cout << "Insert Bureaucrat Grade: ";
		std::cin >> grade;
		std::cin.ignore(1000, '\n');
		std::cout << "Chose Form type [1: ShrubberyCreationForm, 2: RobotomyRequestForm, 3: PresidentialPardonForm]: ";
		std::cin >> formType;
		std::cin.ignore(1000, '\n');
		std::cout << "Chose Form target: ";
		std::getline(std::cin, target);
		switch (formType)
		{
			case 1:
				form = new ShrubberyCreationForm(target);
				break;
			case 2:
				form = new RobotomyRequestForm(target);
				break;
			case 3:
				form = new PresidentialPardonForm(target);
				break;
			default:
				continue;
		}

		try {
			Bureaucrat b(name, grade);
			std::cout << "Name: " << b.getName() << " Grade: " << b.getGrade() << std::endl;
			form->beSigned(b);
			b.executeForm(*form);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		delete form;
	}
	return 0;
}