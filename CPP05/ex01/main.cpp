/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:01 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/06 17:52:49 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::string name;
	std::string formName;
	int grade;
	int formSignGrade;
	int formExeGrade;

	while (!std::cin.eof())
	{
		std::cout << "Insert Bureaucrat Name: ";
		std::getline(std::cin, name);
		if (name.empty())
			continue;
		std::cout << "Insert Bureaucrat Grade: ";
		std::cin >> grade;
		std::cin.ignore(1000, '\n');
		std::cout << "Insert Form Name: ";
		std::getline(std::cin, formName);
		std::cout << "Insert Form Sign Grade: ";
		std::cin >> formSignGrade;
		std::cin.ignore(1000, '\n');
		std::cout << "Insert Form Execution Grade: ";
		std::cin >> formExeGrade;
		std::cin.ignore(1000, '\n');

		try {
			Bureaucrat b(name, grade);
			std::cout << "Name: " << b.getName() << " Grade: " << b.getGrade() << std::endl; 
			Form f(formName, formSignGrade, formExeGrade);
			b.signForm(f);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}