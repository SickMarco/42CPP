/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:25 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/06 17:52:03 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string _name;
	int _grade;
	Bureaucrat();

public:
	Bureaucrat(const std::string& setName, const int setGrade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& src);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void plusGrade();
	void minusGrade();

	void signForm(Form& form) const;
	
	class GradeTooHighException : public std::exception {
	const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif