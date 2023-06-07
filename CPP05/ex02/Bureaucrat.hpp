/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:25 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 14:55:33 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	Bureaucrat();

public:
	Bureaucrat(const std::string& setName, const int setGrade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& src);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void promotion();
	void demotion();

	void signForm(AForm& form) const;
	
	class GradeTooHighException : public std::exception {
	const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	const char* what() const throw();
	};

	void executeForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif