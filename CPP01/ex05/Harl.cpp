/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:36:16 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/22 14:51:02 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl(){}

void Harl::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::error(){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::warning(){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
}

void Harl::info(){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*functions[])() = { &Harl::debug,
									&Harl::info,
									&Harl::warning,
									&Harl::error};

	std::string levels[] = {"DEBUG",
						  "INFO",
						  "WARNING",
						  "ERROR"};

	for (int i = 0; i < 4; i++)
		if (!levels[i].compare(level))
			return (this->*functions[i])();
	std::cout << "Wrong command" << std::endl;
}