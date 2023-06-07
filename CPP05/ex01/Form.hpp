/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:03:32 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 15:30:22 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _exeGrade;
	Form();

public:
	~Form();
	Form(const std::string& setName, const int setSign, const int setExe);
	Form(const Form& src);
	Form& operator=(const Form& src);
	
	std::string getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getExeGrade() const;
	
	void beSigned(const Bureaucrat& b); 

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif