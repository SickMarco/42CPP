/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:34:39 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/01 19:32:09 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <iostream>

class A_Animal
{
protected:
	std::string _type;
public:
	A_Animal();
	virtual ~A_Animal();
	A_Animal(const A_Animal& src);
	A_Animal& operator=(const A_Animal& src);

	virtual void makeSound() const = 0;
	std::string getType() const;
	void setType(const std::string& newName);
};

#endif