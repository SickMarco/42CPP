/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:03:32 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/07 12:07:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _exeGrade;
	AForm();

public:
	virtual ~AForm();
	AForm(const std::string& setName, const int setSign, const int setExe);
	AForm(const AForm& src);

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

	class IsNotSigned : public std::exception {
		const char* what() const throw();
	};

	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif