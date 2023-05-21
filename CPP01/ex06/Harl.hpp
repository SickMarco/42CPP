/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:35:43 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/21 19:35:45 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif